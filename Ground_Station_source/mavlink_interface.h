#ifndef MAVLINK_INTERFACE_H
#define MAVLINK_INTERFACE_H

#include <QThread>
#include <QObject>

// Serial communication:
#include "serialcomm.h"

// MAVLINK messaging protocol:
#include <common/mavlink.h>

// Get actual time-stamp:
#include <QDateTime>

// Time related libraries:
#include <QTimer>
#include <QElapsedTimer>

#include <QDebug>


// ------------------------------------------------------------------------------
//   Data Structures
// ------------------------------------------------------------------------------

struct Time_Stamps
{
    Time_Stamps()
    {
        reset_timestamps();
    }

    uint64_t heartbeat;
    uint64_t sys_status;
    uint64_t battery_status;
    uint64_t radio_status;
    uint64_t local_position_ned;
    uint64_t global_position_int;
    uint64_t position_target_local_ned;
    uint64_t position_target_global_int;
    uint64_t highres_imu;
    uint64_t attitude;

    void reset_timestamps()
    {
        heartbeat = 0;
        sys_status = 0;
        battery_status = 0;
        radio_status = 0;
        local_position_ned = 0;
        global_position_int = 0;
        position_target_local_ned = 0;
        position_target_global_int = 0;
        highres_imu = 0;
        attitude = 0;
    }
};


// Struct containing information on the MAV we are currently connected to
struct Mavlink_Messages {
    int system_ID;
    int component_ID;

    // Heartbeat:
    mavlink_heartbeat_t heartbeat;

    // System Status:
    mavlink_sys_status_t sys_status;

    // System Time:
    mavlink_system_time_t system_time;

    // Ping:
    mavlink_ping_t ping;

    // Battery Status:
    mavlink_battery_status_t battery_status;

    // Radio Status:
    mavlink_radio_status_t radio_status;

    // Local Position:
    mavlink_local_position_ned_t local_position_ned;

    // Global Position:
    mavlink_global_position_int_t global_position_int;

    // Local Position Target:
    mavlink_position_target_local_ned_t position_target_local_ned;

    // Global Position Target:
    mavlink_position_target_global_int_t position_target_global_int;

    // HiRes IMU:
    mavlink_highres_imu_t highres_imu;

    // Attitude:
    mavlink_attitude_t attitude;

    // Scaled IMU:
    mavlink_scaled_imu_t scaled_imu;

    // System Parameters?

    // Time Stamps
    Time_Stamps time_stamps;
    void reset_timestamps()
    {
        time_stamps.reset_timestamps();
    }
};

// Define Mavlink_Messages struct Meta-Type:
Q_DECLARE_METATYPE(Mavlink_Messages)
Q_DECLARE_METATYPE(QVector<QVector<QPointF>>)


class MAVlink_interface : public QObject
{
    Q_OBJECT
public:
    uint8_t ping_request;

    QString serial_portname;
    int serial_baudrate;

    char reading_status;
    char writing_status;
    char control_status;
    uint64_t write_count;

    uint8_t system_ID;
    uint8_t component_ID;

    struct Gamepad_commands
    {
      uint8_t target_system;
      uint16_t roll;
      uint16_t pitch;
      uint16_t yaw;
      uint16_t throttle;
      uint16_t buttons;
    } last_gamepad_commands;

    uint8_t buffer_size[MAVLINK_MAX_PACKET_LEN];

    mavlink_set_position_target_local_ned_t initial_position;
    Mavlink_Messages current_messages;

    QDateTime actual_date_timer;


    explicit MAVlink_interface(QObject *parent = nullptr);
    ~MAVlink_interface();

    void update_setpoint(mavlink_set_position_target_local_ned_t setpoint);
    void stop();
    void handle_quit( int sig );  

signals:
    void setup_serialport(const QString, int);
    void start_timer_serial_comm();
    void update_current_system_data(Mavlink_Messages current_messages);
    void send_data_visualization(QVector<QVector<QPointF>>, QVector<QVector<QPointF>>);

public slots:
    void setup(const QString &portName, int baudrate);
    void switch_serialcomm_mode();
    void read_message();
    void send_message();
    void update_gamepad_commands(QList<double> gamepad_commandedcontrols);
    void update_data_visualization();
    void update_connected_system(QVector<uint8_t>);
    void close_serialcomm();

private:
    uint16_t switch_serial_rate;
    int switch_serial_mode_selector;
    int number_messages_send;
    int send_message_selector[3];

    unsigned long swich_rate_serialcomm;
    uint32_t current_elapsed_time;
    uint32_t last_time_send_manual_control;
    uint32_t last_time_send_heartbeat;

    uint32_t last_read;
    uint32_t last_something_read;

    uint16_t buffer_size_graphics;
    QVector<QVector<QPointF>> buffer_commands_test;
    QVector<QVector<QPointF>> buffer_state_variables_test;

    QVector<double> last_time_stamps;
    QVector<double> last_state_variables;
    QVector<double> last_commands;

    mavlink_status_t status;

    mavlink_set_position_target_local_ned_t current_setpoint;

    SerialComm *serialcomm;

    QTimer *timer_serialcomm;
    QElapsedTimer elapsed_timer;


    uint64_t time_usec;
    uint32_t sequence = 0;

    // Connected system variables:
    QVector<uint8_t> connected_system;

    // Define the system type, in this case an airplane -> on-board controller
    uint8_t system_type = MAV_TYPE_GCS;
    uint8_t autopilot_type = MAV_AUTOPILOT_INVALID;

    uint8_t system_mode = MAV_MODE_PREFLIGHT; ///< Booting up
    uint32_t custom_mode = 0;                 ///< Custom mode, can be defined by user/adopter
    uint8_t system_state = MAV_STATE_STANDBY; ///< System ready for flight
};

#endif // MAVLINK_INTERFACE_H
