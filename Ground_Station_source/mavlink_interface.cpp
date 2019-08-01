#include "mavlink_interface.h"


// ------------------------------------------------------------------------------
//   Constructor
// ------------------------------------------------------------------------------
MAVlink_interface::MAVlink_interface(QObject *parent) : QObject(parent)
{
    // Register Mavlink_Messages in order to allow signal/slot connections:
    qRegisterMetaType<Mavlink_Messages>();
    qRegisterMetaType<QVector<QVector<QPointF>>>();

    // Initialize attributes:
    ping_request = 0;

    write_count = 0;

    reading_status = 0;      // whether the read thread is running
    writing_status = 0;      // whether the write thread is running
    control_status = 0;      // whether the autopilot is in offboard control mode

    system_ID = 255; // System ID.
    component_ID = 1; // Autopilot component ID.

    last_time_stamps = QVector<double>(3);
    last_state_variables = QVector<double>(6);
    last_commands = QVector<double>(6);
    last_gamepad_commands.buttons = 0;

    // Initialize variables:
    buffer_size_graphics = 50;

    buffer_commands_test = QVector<QVector<QPointF>>(6, QVector<QPointF>(buffer_size_graphics));
    buffer_state_variables_test = QVector<QVector<QPointF>>(6, QVector<QPointF>(buffer_size_graphics));
}

// ------------------------------------------------------------------------------
//   Deconstructor
// ------------------------------------------------------------------------------
MAVlink_interface::~MAVlink_interface()
{
}


// ------------------------------------------------------------------------------
//   STARTUP
// ------------------------------------------------------------------------------
void MAVlink_interface::setup(const QString &portName, int baudrate)
{
    // Creates serial and thread objects:
    serialcomm = new SerialComm;
    timer_serialcomm = new QTimer;

    // Setup serial communications:
    serialcomm->setup_serial(portName, baudrate);

    // Connect timer timeout with switch serial mode function:
    connect(timer_serialcomm, SIGNAL(timeout()), this, SLOT(switch_serialcomm_mode()));

    // Pre-define serial mode as read:
    switch_serial_mode_selector = 0;

    // Start timer switch read/send messages:
    switch_serial_rate = 20;
    timer_serialcomm->start(switch_serial_rate);

    // Initiate clock for time coordinating send messages:
    elapsed_timer.start();

    number_messages_send = 0;
    send_message_selector[0] = 0;
    send_message_selector[1] = 0;
    send_message_selector[2] = 0;  
}


void MAVlink_interface::switch_serialcomm_mode()
{
    switch_serial_mode_selector = abs(switch_serial_mode_selector - 1);
    if (switch_serial_mode_selector == 0)
    {
        // Call read message function:
        read_message();
    }
    else if (switch_serial_mode_selector == 1)
    {
        // Call send message function:
        send_message();
    }
}

// ------------------------------------------------------------------------------
//   Read Messages
// ------------------------------------------------------------------------------
void MAVlink_interface::read_message()
{
    Time_Stamps this_timestamps;

    mavlink_message_t message;

    // Read serial port:
    QByteArray raw_serial_data = serialcomm->read_serial_message();

    for (int i = 0; i <= raw_serial_data.size(); i++)
    {
        if (mavlink_parse_char(MAVLINK_COMM_1, raw_serial_data[i], &message, &status))
        {
            // Store message sysid and compid.
            // Note this doesn't handle multiple message sources.
            current_messages.system_ID  = message.sysid;
            current_messages.component_ID = message.compid;

            // Handle Message ID
            switch (message.msgid) {
            case MAVLINK_MSG_ID_HEARTBEAT:
            {
                mavlink_msg_heartbeat_decode(&message, &(current_messages.heartbeat));
                //current_elapsed_time = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
                //qDebug() << "Something to be read :" << current_elapsed_time - last_something_read;
                //last_something_read = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
                break;
            }
            case MAVLINK_MSG_ID_SYS_STATUS:
            {

            }
            case MAVLINK_MSG_ID_PING:
            {
               mavlink_msg_ping_decode(&message, &(current_messages.ping));

               current_messages.ping.time_usec = elapsed_timer.nsecsElapsed()/(uint64_t)1000 - current_messages.ping.time_usec;
               break;
            }
            case MAVLINK_MSG_ID_BATTERY_STATUS:
            {
                mavlink_msg_battery_status_decode(&message, &(current_messages.battery_status));
                break;
            }
            case MAVLINK_MSG_ID_RADIO_STATUS:
            {

            }
            case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
            {

            }
            case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
            {
                mavlink_msg_global_position_int_decode(&message, &(current_messages.global_position_int));

                last_time_stamps[1] = current_messages.global_position_int.time_boot_ms;

                last_state_variables[3] = current_messages.global_position_int.lat;
                last_state_variables[4] = current_messages.global_position_int.lon;
                last_state_variables[5] = current_messages.global_position_int.alt;

                for (uint8_t i = 3; i < 6; i++) {
                    buffer_state_variables_test[i].removeFirst();
                    buffer_state_variables_test[i].append(QPointF(last_time_stamps[1], last_state_variables[i]));
                }
                break;
            }
            case MAVLINK_MSG_ID_HIGHRES_IMU:
            {

            }
            case MAVLINK_MSG_ID_ATTITUDE:
            {
                mavlink_msg_attitude_decode(&message, &(current_messages.attitude));

                last_time_stamps[0] = current_messages.attitude.time_boot_ms;

                last_state_variables[0] = current_messages.attitude.roll;
                last_state_variables[1] = current_messages.attitude.pitch;
                last_state_variables[2] = current_messages.attitude.yaw;

                for (uint8_t i = 0; i < 3; i++) {
                    buffer_state_variables_test[i].removeFirst();
                    buffer_state_variables_test[i].append(QPointF(last_time_stamps[0], last_state_variables[i]));
                }
                //current_elapsed_time = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
                //qDebug() << "Attitude time :" << current_elapsed_time - last_read;
                //last_read = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
                //qDebug() << "Roll, Pitch, Yaw" << current_messages.attitude.roll << ", " << current_messages.attitude.pitch << ", " << current_messages.attitude.yaw;
                break;
            }
            case MAVLINK_MSG_ID_SCALED_IMU:
            {
                mavlink_msg_scaled_imu_decode(&message, &(current_messages.scaled_imu));
                break;
            }
            } // End swicth.

            // Pass system's data to Ground Station Main Window:
            emit this->update_current_system_data(current_messages);
        }
    } // End for.



    //    // Blocking wait for new data
//    while ( !received_all and !time_to_exit )
//    {
//        // ----------------------------------------------------------------------
//        //   READ MESSAGE
//        // ----------------------------------------------------------------------
//        mavlink_message_t message;
//        //success = serialcomm->read_serial_message(message);

//        // ----------------------------------------------------------------------
//        //   HANDLE MESSAGE
//        // ----------------------------------------------------------------------
//        if( success )
//        {
//            // Store message sysid and compid.
//            // Note this doesn't handle multiple message sources.
//            current_messages.sysid  = message.sysid;
//            current_messages.compid = message.compid;

//            // Handle Message ID
//            switch (message.msgid)
//            {
//                case MAVLINK_MSG_ID_HEARTBEAT:
//                {
//                    //printf("MAVLINK_MSG_ID_HEARTBEAT\n");
//                    mavlink_msg_heartbeat_decode(&message, &(current_messages.heartbeat));
//                    current_messages.time_stamps.heartbeat = get_time_usec();
//                    this_timestamps.heartbeat = current_messages.time_stamps.heartbeat;
//                    break;
//                }
//                case MAVLINK_MSG_ID_SYS_STATUS:
//                {
//                    //printf("MAVLINK_MSG_ID_SYS_STATUS\n");
//                    mavlink_msg_sys_status_decode(&message, &(current_messages.sys_status));
//                    current_messages.time_stamps.sys_status = get_time_usec();
//                    this_timestamps.sys_status = current_messages.time_stamps.sys_status;
//                    break;
//                }
//                case MAVLINK_MSG_ID_BATTERY_STATUS:
//                {
//                    //printf("MAVLINK_MSG_ID_BATTERY_STATUS\n");
//                    mavlink_msg_battery_status_decode(&message, &(current_messages.battery_status));
//                    current_messages.time_stamps.battery_status = get_time_usec();
//                    this_timestamps.battery_status = current_messages.time_stamps.battery_status;
//                    break;
//                }
//                case MAVLINK_MSG_ID_RADIO_STATUS:
//                {
//                    //printf("MAVLINK_MSG_ID_RADIO_STATUS\n");
//                    mavlink_msg_radio_status_decode(&message, &(current_messages.radio_status));
//                    current_messages.time_stamps.radio_status = get_time_usec();
//                    this_timestamps.radio_status = current_messages.time_stamps.radio_status;
//                    break;
//                }
//                case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
//                {
//                    //printf("MAVLINK_MSG_ID_LOCAL_POSITION_NED\n");
//                    mavlink_msg_local_position_ned_decode(&message, &(current_messages.local_position_ned));
//                    current_messages.time_stamps.local_position_ned = get_time_usec();
//                    this_timestamps.local_position_ned = current_messages.time_stamps.local_position_ned;
//                    break;
//                }
//                case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
//                {
//                    //printf("MAVLINK_MSG_ID_GLOBAL_POSITION_INT\n");
//                    mavlink_msg_global_position_int_decode(&message, &(current_messages.global_position_int));
//                    current_messages.time_stamps.global_position_int = get_time_usec();
//                    this_timestamps.global_position_int = current_messages.time_stamps.global_position_int;
//                    break;
//                }
//                case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED:
//                {
//                    //printf("MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED\n");
//                    mavlink_msg_position_target_local_ned_decode(&message, &(current_messages.position_target_local_ned));
//                    current_messages.time_stamps.position_target_local_ned = get_time_usec();
//                    this_timestamps.position_target_local_ned = current_messages.time_stamps.position_target_local_ned;
//                    break;
//                }
//                case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT:
//                {
//                    //printf("MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT\n");
//                    mavlink_msg_position_target_global_int_decode(&message, &(current_messages.position_target_global_int));
//                    current_messages.time_stamps.position_target_global_int = get_time_usec();
//                    this_timestamps.position_target_global_int = current_messages.time_stamps.position_target_global_int;
//                    break;
//                }
//                case MAVLINK_MSG_ID_HIGHRES_IMU:
//                {
//                    //printf("MAVLINK_MSG_ID_HIGHRES_IMU\n");
//                    mavlink_msg_highres_imu_decode(&message, &(current_messages.highres_imu));
//                    current_messages.time_stamps.highres_imu = get_time_usec();
//                    this_timestamps.highres_imu = current_messages.time_stamps.highres_imu;
//                    break;
//                }
//                case MAVLINK_MSG_ID_ATTITUDE:
//                {
//                    //printf("MAVLINK_MSG_ID_ATTITUDE\n");
//                    mavlink_msg_attitude_decode(&message, &(current_messages.attitude));
//                    current_messages.time_stamps.attitude = get_time_usec();
//                    this_timestamps.attitude = current_messages.time_stamps.attitude;
//                    break;
//                }
//                default:
//                {
//                    // printf("Warning, did not handle message id %i\n",message.msgid);
//                    break;
//                }
//            } // end: switch msgid

//        } // end: if read message

//        // Check for receipt of all items
//        received_all =
//                this_timestamps.heartbeat                  &&
// //				this_timestamps.battery_status             &&
// //				this_timestamps.radio_status               &&
// //				this_timestamps.local_position_ned         &&
// //				this_timestamps.global_position_int        &&
// //				this_timestamps.position_target_local_ned  &&
// //				this_timestamps.position_target_global_int &&
// //				this_timestamps.highres_imu                &&
// //				this_timestamps.attitude                   &&
//                this_timestamps.sys_status
//                ;

//        // give the write thread time to use the port
//        if ( writing_status > false ) {
//            //usleep(100); // look for components of batches at 10kHz
//        }

//    } // end: while not received all

//    return;
}

// ------------------------------------------------------------------------------
//   Send Messages
// ------------------------------------------------------------------------------
void MAVlink_interface::send_message()
{
    // Initialize MAVlink message:
    mavlink_message_t message;

    current_elapsed_time = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
    if (current_elapsed_time - last_time_send_manual_control >= 20)
    {
        // Manual control commands are sent every 20 milliseconds:
        send_message_selector[number_messages_send] = 1;
        number_messages_send += 1;
    }

    if (current_elapsed_time - last_time_send_heartbeat >= 1000)
    {
        // Heartbeat message is sent every 1 second:
        send_message_selector[number_messages_send] = 2;
        number_messages_send += 1;
    }

    if (ping_request == 1)
    {
        // PING message requested:
        send_message_selector[number_messages_send] = 3;
        number_messages_send += 1;

        //ping_request = 0;
    }

    for(uint8_t i = 0; i < number_messages_send; i++)
    {
        if (send_message_selector[i] == 1)
        {
        // Pack the manual control message:
        mavlink_msg_manual_control_pack(system_ID, component_ID, &message, last_gamepad_commands.target_system,
                                        last_gamepad_commands.roll, last_gamepad_commands.pitch, last_gamepad_commands.yaw,
                                        last_gamepad_commands.throttle, last_gamepad_commands.buttons);

        // Update timers for messages:
        last_time_send_manual_control = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
        }
        else if (send_message_selector[i] == 2)
        {
            mavlink_msg_heartbeat_pack(system_ID, component_ID, &message, system_type, autopilot_type, system_mode, custom_mode, system_state);

            // Update timers for messages:
            last_time_send_heartbeat = elapsed_timer.nsecsElapsed()/(uint32_t)1000000;
        }
        else if (send_message_selector[i] == 3)
        {
            // Read actual time:
            time_usec = elapsed_timer.nsecsElapsed()/(uint64_t)1000;

            mavlink_msg_ping_pack(system_ID, component_ID, &message, time_usec, sequence, 0, 0);

            // Update sequence for next PING:
            //sequence++;
        }

        // Calculate message length considering buffer size:
        uint8_t buffer_size[MAVLINK_MAX_PACKET_LEN];

        uint16_t length = mavlink_msg_to_send_buffer(buffer_size, &message);

        // Send message:
        serialcomm->write_serial_message(buffer_size, length);
    }

    // Reset message's identifiers and counters:
    number_messages_send = 0;
    send_message_selector[0] = 0;
    send_message_selector[1] = 0;
    send_message_selector[2] = 0;
}

void MAVlink_interface::update_gamepad_commands(QList<double> gamepad_commandedcontrols)
{
    last_gamepad_commands.target_system = 1;
    last_gamepad_commands.roll = gamepad_commandedcontrols.at(0) * 1000;
    last_gamepad_commands.pitch = - gamepad_commandedcontrols.at(1) * 1000;
    last_gamepad_commands.yaw = gamepad_commandedcontrols.at(2) * 1000;
    last_gamepad_commands.throttle = - gamepad_commandedcontrols.at(3) * 1000;

    last_gamepad_commands.buttons = 0;
    for (uint8_t i = 0; i <= 15; i++){
        last_gamepad_commands.buttons += pow(2, i) * gamepad_commandedcontrols.at(i + 4);
    }

    last_time_stamps[2] = elapsed_timer.elapsed();

    last_commands[3] = static_cast<double>(- gamepad_commandedcontrols.at(3));
    last_commands[0] = static_cast<double>(gamepad_commandedcontrols.at(0));
    last_commands[1] = static_cast<double>(- gamepad_commandedcontrols.at(1));
    last_commands[2] = static_cast<double>(gamepad_commandedcontrols.at(2));

    for (uint8_t i = 0; i < 6; i++) {
        buffer_commands_test[i].removeFirst();
        buffer_commands_test[i].append(QPointF(last_time_stamps[2], last_commands[i]));
    }
}

void MAVlink_interface::update_data_visualization()
{
    // Update last received state variables for displaying:
    emit send_data_visualization(buffer_state_variables_test, buffer_commands_test);
}

void MAVlink_interface::update_connected_system(QVector<uint8_t> new_connected_system)
{
    connected_system = new_connected_system;
}

void MAVlink_interface::close_serialcomm()
{
    // Disconnect all serial communication functions:
    disconnect(timer_serialcomm, SIGNAL(timeout()), this, SLOT(switch_serialcomm_mode()));

    // Close current serialcomm object:
    serialcomm->stop_serial();

    // Restore to default serial objects:
    delete serialcomm;
    delete timer_serialcomm;
}
