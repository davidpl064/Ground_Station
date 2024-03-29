import QtQuick 2.12
import QtLocation 5.11

MapQuickItem {
    id: marker
    property alias lastMouseX: markerMouseArea.lastX
    property alias lastMouseY: markerMouseArea.lastY

    anchorPoint.x: image.width/4
    anchorPoint.y: image.height

    sourceItem: Image {
        id: image
        source: "../icons/marker.png"
        opacity: markerMouseArea.pressed ? 0.6 : 1.0
        MouseArea  {
            id: markerMouseArea
            property int pressX : -1
            property int pressY : -1
            property int jitterThreshold : 10
            property int lastX: -1
            property int lastY: -1
            anchors.fill: parent
            hoverEnabled : false
            drag.target: marker
            preventStealing: true
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onPressed : {
                map.pressX = mouse.x
                map.pressY = mouse.y
                map.currentMarker = -1
                for (var i = 0; i < map.markers.length; i++){
                    if (marker == map.markers[i]){
                        map.currentMarker = i
                        break
                    }
                }
            }

            onClicked: {
                if(mouse.button & Qt.RightButton) {
                    if (Math.abs(map.pressX - mouse.x ) < map.jitterThreshold
                            && Math.abs(map.pressY - mouse.y ) < map.jitterThreshold) {
                        var p = map.fromCoordinate(marker.coordinate)
                        lastX = p.x
                        lastY = p.y
                        map.showMarkerMenu(marker.coordinate)
                    }
                }
            }
        }

        Text{
            id: number
            y: image.height/10
            width: image.width
            color: "white"
            font.bold: true
            font.pixelSize: 14
            horizontalAlignment: Text.AlignHCenter
            Component.onCompleted: {
                text = map.markerCounter
            }
        }

    }

    Component.onCompleted: coordinate = map.toCoordinate(Qt.point(markerMouseArea.mouseX,
                                                                  markerMouseArea.mouseY));
}
