import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtLocation 5.11
import QtPositioning 5.11

import "../helper.js" as Helper

Map {
    id: map
    //anchors.fill: parent

    plugin: Plugin {
        name: "mapbox"

        PluginParameter {
            name: "mapbox.access_token"
            value: "pk.eyJ1Ijoic2ljYXJpdXMwNjQiLCJhIjoiY2pkbHl1YTBpMGNrZTJ2bGppODZzem40dyJ9.CMKEMVKwl3EWB6Ls2hntAQ"
        }
        //            PluginParameter {
        //                name: "mapbox.mapping.additional_style_urls"
        //                value: "mapbox://styles/mapbox/satellite-v9"
        //            }
        //            PluginParameter {
        //                name: "mapbox.mapping.use_fbo"
        //                value: false
        //            }
    }

    //    //        center: QtPositioning.coordinate(59.930243, 10.714635)
    //    //        zoomLevel: 15


    //    MapParameter {
    //        type: "source"

    //        property var name: "routeSource"
    //        property var sourceType: "vector"
    //        property var url: "mapbox://styles/mapbox/streets-v10"
    //    }

    //    MapParameter {
    //        type: "layer"

    //        property var name: "route"
    //        property var layerType: "line"
    //        property var source: "routeSource"

    //        // Draw under the first road label layer
    //        // of the mapbox-streets style.
    //        property var before: "road-label-small"
    //    }

    //    MapParameter {
    //        type: "paint"

    //        property var layer: "route"
    //        property var lineColor: "blue"
    //        property var lineWidth: 8.0
    //    }

    //    MapParameter {
    //        type: "layout"

    //        property var layer: "route"
    //        property var lineJoin: "round"
    //        property var lineCap: "round"
    //    }

    //    // Enable pan, flick, and pinch gestures to zoom in and out:
    //    gesture.acceptedGestures: MapGestureArea.PanGesture | MapGestureArea.FlickGesture | MapGestureArea.PinchGesture | MapGestureArea.RotationGesture | MapGestureArea.TiltGesture
    //    gesture.flickDeceleration: 3000
    //    gesture.enabled: true

    //    PositionSource {
    //        onPositionChanged: {
    //            // Center the map on the default Qt position (Oslo):
    //            map.center = QtPositioning.coordinate(59.930243, 10.714635)
    //        }
    //    }

    //    GeocodeModel {
    //        id: geocode_Model
    //        plugin: map.plugin
    //        onStatusChanged: {
    //            if ((status == GeocodeModel.Ready) || (status == GeocodeModel.Error))
    //                map.geocodeFinished()
    //        }
    //        onLocationsChanged:
    //        {
    //            if (count == 1) {
    //                map.center.latitude = get(0).coordinate.latitude
    //                map.center.longitude = get(0).coordinate.longitude
    //            }
    //        }
    //    }

    //    RouteModel {
    //        id: route_Model
    //        plugin : map.plugin
    //        query:  RouteQuery {
    //            id: route_Query
    //        }
    //        onStatusChanged: {
    //            if (status == RouteModel.Ready)
    //            {
    //                switch (count) {
    //                case 0:
    //                    // Technically not an error:
    //                    map.routeError()
    //                    break
    //                case 1:
    //                    map.showRouteList()
    //                    break
    //                }
    //            }
    //            else if (status == RouteModel.Error) {
    //                map.routeError()
    //            }
    //        }
    //    }

    //    Component {
    //        id: pointDelegate

    //        MapCircle {
    //            id: point
    //            radius: 1000
    //            color: "#46a2da"
    //            border.color: "#190a33"
    //            border.width: 2
    //            smooth: true
    //            opacity: 0.25
    //            center: locationData.coordinate
    //        }
    //    }


    property var markers
    property var mapItems
    property int markerCounter: 0 // counter for total amount of markers. Resets to 0 when number of markers = 0
    property int currentMarker
    property int lastX : -1
    property int lastY : -1
    property int pressX : -1
    property int pressY : -1
    property int jitterThreshold : 30
    property bool followme: false
    property var scaleLengths: [5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000, 2000000]
    property alias routeQuery: routeQuery
    property alias routeModel: routeModel
    property alias geocodeModel: geocodeModel

    signal showGeocodeInfo()
    signal geocodeFinished()
    signal routeError()
    signal coordinatesCaptured(double latitude, double longitude)
    signal showMainMenu(var coordinate)
    signal showMarkerMenu(var coordinate)
    signal showRouteMenu(var coordinate)
    signal showPointMenu(var coordinate)
    signal showRouteList()

    function geocodeMessage()
    {
        var street, district, city, county, state, countryCode, country, postalCode, latitude, longitude, text
        latitude = Math.round(geocodeModel.get(0).coordinate.latitude * 10000) / 10000
        longitude = Math.round(geocodeModel.get(0).coordinate.longitude * 10000) / 10000
        street = geocodeModel.get(0).address.street
        district = geocodeModel.get(0).address.district
        city = geocodeModel.get(0).address.city
        county = geocodeModel.get(0).address.county
        state = geocodeModel.get(0).address.state
        countryCode = geocodeModel.get(0).address.countryCode
        country = geocodeModel.get(0).address.country
        postalCode = geocodeModel.get(0).address.postalCode

        text = "<b>Latitude:</b> " + latitude + "<br/>"
        text +="<b>Longitude:</b> " + longitude + "<br/>" + "<br/>"
        if (street) text +="<b>Street: </b>"+ street + " <br/>"
        if (district) text +="<b>District: </b>"+ district +" <br/>"
        if (city) text +="<b>City: </b>"+ city + " <br/>"
        if (county) text +="<b>County: </b>"+ county + " <br/>"
        if (state) text +="<b>State: </b>"+ state + " <br/>"
        if (countryCode) text +="<b>Country code: </b>"+ countryCode + " <br/>"
        if (country) text +="<b>Country: </b>"+ country + " <br/>"
        if (postalCode) text +="<b>PostalCode: </b>"+ postalCode + " <br/>"
        return text
    }

    function calculateScale()
    {
        var coord1, coord2, dist, text, f
        f = 0
        coord1 = map.toCoordinate(Qt.point(0,scale.y))
        coord2 = map.toCoordinate(Qt.point(0+scaleImage.sourceSize.width,scale.y))
        dist = Math.round(coord1.distanceTo(coord2))

        if (dist === 0) {
            // not visible
        }
        else {
            for (var i = 0; i < scaleLengths.length-1; i++) {
                if (dist < (scaleLengths[i] + scaleLengths[i+1]) / 2 ) {
                    f = scaleLengths[i] / dist
                    dist = scaleLengths[i]
                    break;
                }
            }
            if (f === 0) {
                f = dist / scaleLengths[i]
                dist = scaleLengths[i]
            }
        }

        text = Helper.formatDistance(dist)
        scaleImage.width = (scaleImage.sourceSize.width * f) - 2 * scaleImageLeft.sourceSize.width
        scaleText.text = text
    }

    function deleteMarkers()
    {
        var count = map.markers.length
        for (var i = 0; i < count; i++){
            map.removeMapItem(map.markers[i])
            map.markers[i].destroy()
        }
        map.markers = []
        markerCounter = 0
    }

    function deleteMapItems()
    {
        var count = map.mapItems.length
        for (var i = 0; i < count; i++){
            map.removeMapItem(map.mapItems[i])
            map.mapItems[i].destroy()
        }
        map.mapItems = []
    }

    function addMarker()
    {
        // Get existing markers:
        var count = map.markers.length

        // Add new marker to counter:
        markerCounter++

        // Create new marker object and add it to the map:
        var marker = Qt.createQmlObject ('Marker {}', map)
        map.addMapItem(marker)

        // Overlay the marker on the map:
        marker.z = map.z + 1
        marker.coordinate = mouseArea.lastCoordinate

        // Update list of markers:
        var aux_array = new Array
        for (var i = 0; i < count; i++){
            aux_array.push(markers[i])
        }
        aux_array.push(marker)
        markers = aux_array
    }

    function addGeoItem(item)
    {
        var count = map.mapItems.length

        var co = Qt.createComponent(item + '.qml')
        if (co.status == Component.Ready) {
            var o = co.createObject(map)
            o.setGeometry(map.markers, currentMarker)
            map.addMapItem(o)

            // Update list of items:
            var aux_array
            for (var i = 0; i < count; i++){
                aux_array.push(markers[i])
            }
            aux_array.push(o)
            mapItems = aux_array

        } else {
            console.log(item + " is not supported right now, please call us later.")
        }
    }

    function deleteMarker(index)
    {
        // Update list of markers:
        var aux_array = new Array

        var count = map.markers.length
        for (var i = 0; i < count; i++){
            if (index != i) aux_array.push(map.markers[i])
        }

        map.removeMapItem(map.markers[index])
        map.markers[index].destroy()
        map.markers = aux_array
        if (markers.length == 0) markerCounter = 0
    }

    function calculateMarkerRoute()
    {
        // Clear away any old data in the query:
        routeQuery.clearWaypoints();

        for (var i = currentMarker; i < map.markers.length; i++){
            routeQuery.addWaypoint(markers[i].coordinate)
        }

        // Configure the RouteQuery:
        routeQuery.travelModes = RouteQuery.PedestrianTravel
        routeQuery.routeOptimizations = RouteQuery.ShortestRoute
        routeQuery.setFeatureWeight(0, 0)

        // Calculate the route:
        routeModel.update();
    }

    function calculateCoordinateRoute(startCoordinate, endCoordinate)
    {
        // Clear away any old data in the query
        routeQuery.clearWaypoints();

        // Add the start and end coords as waypoints on the route
        routeQuery.addWaypoint(startCoordinate)
        routeQuery.addWaypoint(endCoordinate)

        // Configure the RouteQuery:
        routeQuery.travelModes = RouteQuery.PedestrianTravel
        routeQuery.routeOptimizations = RouteQuery.ShortestRoute

        for (var i = 0; i < 9; i++) {
            routeQuery.setFeatureWeight(i, 0)
        }
        //for (var i=0; i<routeDialog.features.length; i++) {
        //    map.routeQuery.setFeatureWeight(routeDialog.features[i], RouteQuery.AvoidFeatureWeight)
        //}

        routeModel.update();

        // Center the map on the start coordinate:
        map.center = startCoordinate;
    }

    function geocode(fromAddress)
    {
        // Send the geocode request:
        geocodeModel.query = fromAddress
        geocodeModel.update()
    }

    zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
    center {
        // The Qt Company in Oslo
        latitude: 59.9485
        longitude: 10.7686
    }

    // Enable pan, flick, and pinch gestures to zoom in and out:
    gesture.acceptedGestures: MapGestureArea.PanGesture | MapGestureArea.FlickGesture | MapGestureArea.PinchGesture | MapGestureArea.RotationGesture | MapGestureArea.TiltGesture
    gesture.flickDeceleration: 3000
    gesture.enabled: true
    focus: true

    onCenterChanged: {
        scaleTimer.restart()
        if (map.followme)
            if (map.center != positionSource.position.coordinate) map.followme = false
    }

    onZoomLevelChanged: {
        scaleTimer.restart()
        if (map.followme) map.center = positionSource.position.coordinate
    }

    onWidthChanged: {
        scaleTimer.restart()
    }

    onHeightChanged: {
        scaleTimer.restart()
    }

    Component.onCompleted: {
        markers = new Array
        mapItems = new Array
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Plus) {
            map.zoomLevel++;
        } else if (event.key === Qt.Key_Minus) {
            map.zoomLevel--;
        } else if (event.key === Qt.Key_Left || event.key === Qt.Key_Right ||
                   event.key === Qt.Key_Up   || event.key === Qt.Key_Down) {
            var dx = 0;
            var dy = 0;

            switch (event.key) {

            case Qt.Key_Left: dx = map.width / 4; break;
            case Qt.Key_Right: dx = -map.width / 4; break;
            case Qt.Key_Up: dy = map.height / 4; break;
            case Qt.Key_Down: dy = -map.height / 4; break;

            }

            var mapCenterPoint = Qt.point(map.width / 2.0 - dx, map.height / 2.0 - dy);
            map.center = map.toCoordinate(mapCenterPoint);
        }
    }

    /* @todo
        Binding {
            target: map
            property: 'center'
            value: positionSource.position.coordinate
            when: followme
        }*/

    PositionSource{
        id: positionSource
        active: followme

        onPositionChanged: {
            map.center = positionSource.position.coordinate
        }
    }

    MapQuickItem {
        id: poiTheQtComapny
        sourceItem: Rectangle { width: 14; height: 14; color: "#e41e25"; border.width: 2; border.color: "white"; smooth: true; radius: 7 }
        coordinate {
            latitude: 59.9485
            longitude: 10.7686
        }
        opacity: 1.0
        anchorPoint: Qt.point(sourceItem.width/2, sourceItem.height/2)
    }

    MapQuickItem {
        sourceItem: Text{
            text: "The Qt Company"
            color:"#242424"
            font.bold: true
            styleColor: "#ECECEC"
            style: Text.Outline
        }
        coordinate: poiTheQtComapny.coordinate
        anchorPoint: Qt.point(-poiTheQtComapny.sourceItem.width * 0.5,poiTheQtComapny.sourceItem.height * 1.5)
    }

    Item {
        id: scale
        z: map.z + 3
        visible: scaleText.text != "0 m"
        anchors.bottom: parent.bottom;
        anchors.right: parent.right
        anchors.margins: 20
        height: scaleText.height * 2
        width: scaleImage.width

        Image {
            id: scaleImageLeft
            source: "../icons/scale_end.png"
            anchors.bottom: parent.bottom
            anchors.right: scaleImage.left
        }
        Image {
            id: scaleImage
            source: "../icons/scale.png"
            anchors.bottom: parent.bottom
            anchors.right: scaleImageRight.left
        }
        Image {
            id: scaleImageRight
            source: "../icons/scale_end.png"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
        }
        Label {
            id: scaleText
            color: "#004EAE"
            anchors.centerIn: parent
            text: "0 m"
        }
        Component.onCompleted: {
            map.calculateScale();
        }
    }

    RouteModel {
        id: routeModel
        plugin : map.plugin
        query:  RouteQuery {
            id: routeQuery
        }
        onStatusChanged: {
            if (status == RouteModel.Ready) {
                switch (count) {
                case 0:
                    // Technically not an error:
                    map.routeError()
                    break
                case 1:
                    map.showRouteList()
                    break
                }
            } else if (status == RouteModel.Error) {
                map.routeError()
            }
        }
    }

    Component {
        id: routeDelegate

        MapRoute {
            id: route
            route: routeData
            line.color: "#46a2da"
            line.width: 5
            smooth: true
            opacity: 0.8
            MouseArea {
                id: routeMouseArea
                anchors.fill: parent
                hoverEnabled: false
                property variant lastCoordinate

                onPressed : {
                    map.lastX = mouse.x + parent.x
                    map.lastY = mouse.y + parent.y
                    map.pressX = mouse.x + parent.x
                    map.pressY = mouse.y + parent.y
                    lastCoordinate = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                }

                onPositionChanged: {
                    if (mouse.button == Qt.LeftButton) {
                        map.lastX = mouse.x + parent.x
                        map.lastY = mouse.y + parent.y
                    }
                }

                onPressAndHold:{
                    if (Math.abs(map.pressX - parent.x- mouse.x ) < map.jitterThreshold
                            && Math.abs(map.pressY - parent.y - mouse.y ) < map.jitterThreshold) {
                        showRouteMenu(lastCoordinate);
                    }
                }

            }
        }
    }

    GeocodeModel {
        id: geocodeModel
        plugin: map.plugin
        onStatusChanged: {
            if ((status == GeocodeModel.Ready) || (status == GeocodeModel.Error))
                map.geocodeFinished()
        }
        onLocationsChanged:
        {
            if (count == 1) {
                map.center.latitude = get(0).coordinate.latitude
                map.center.longitude = get(0).coordinate.longitude
            }
        }
    }

    Component {
        id: pointDelegate

        MapCircle {
            id: point
            radius: 1000
            color: "#46a2da"
            border.color: "#190a33"
            border.width: 2
            smooth: true
            opacity: 0.25
            center: locationData.coordinate
            MouseArea {
                anchors.fill:parent
                id: circleMouseArea
                hoverEnabled: false
                property variant lastCoordinate

                onPressed : {
                    map.lastX = mouse.x + parent.x
                    map.lastY = mouse.y + parent.y
                    map.pressX = mouse.x + parent.x
                    map.pressY = mouse.y + parent.y
                    lastCoordinate = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                }

                onPositionChanged: {
                    if (Math.abs(map.pressX - parent.x- mouse.x ) > map.jitterThreshold ||
                            Math.abs(map.pressY - parent.y -mouse.y ) > map.jitterThreshold) {
                        if (pressed) parent.radius = parent.center.distanceTo(
                                         map.toCoordinate(Qt.point(mouse.x, mouse.y)))
                    }
                    if (mouse.button == Qt.LeftButton) {
                        map.lastX = mouse.x + parent.x
                        map.lastY = mouse.y + parent.y
                    }
                }

                onPressAndHold:{
                    if (Math.abs(map.pressX - parent.x - mouse.x ) < map.jitterThreshold
                            && Math.abs(map.pressY - parent.y - mouse.y ) < map.jitterThreshold) {
                        showPointMenu(lastCoordinate);
                    }
                }
            }
        }
    }

    MapItemView {
        model: routeModel
        delegate: routeDelegate
        autoFitViewport: true
    }

    MapItemView {
        model: geocodeModel
        delegate: pointDelegate
    }

    Timer {
        id: scaleTimer
        interval: 100
        running: false
        repeat: false
        onTriggered: {
            map.calculateScale()
        }
    }

    MouseArea {
        id: mouseArea
        property variant lastCoordinate
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            map.pressX = mouse.x
            map.pressY = mouse.y
            map.lastX = mouse.x
            map.lastY = mouse.y
            lastCoordinate = map.toCoordinate(Qt.point(mouse.x, mouse.y))

            if(mouse.button & Qt.RightButton) {
                if (Math.abs(map.pressX - mouse.x ) < map.jitterThreshold
                        && Math.abs(map.pressY - mouse.y ) < map.jitterThreshold) {
                    showMainMenu(lastCoordinate);
                }
            }
        }

        onPositionChanged: {
            if (mouse.button == Qt.LeftButton) {
                map.lastX = mouse.x
                map.lastY = mouse.y
            }
        }

        onDoubleClicked: {
            var mouseGeoPos = map.toCoordinate(Qt.point(mouse.x, mouse.y));
            var preZoomPoint = map.fromCoordinate(mouseGeoPos, false);
            if (mouse.button === Qt.LeftButton) {
                map.zoomLevel = Math.floor(map.zoomLevel + 1)
            } else if (mouse.button === Qt.RightButton) {
                map.zoomLevel = Math.floor(map.zoomLevel - 1)
            }
            var postZoomPoint = map.fromCoordinate(mouseGeoPos, false);
            var dx = postZoomPoint.x - preZoomPoint.x;
            var dy = postZoomPoint.y - preZoomPoint.y;

            var mapCenterPoint = Qt.point(map.width / 2.0 + dx, map.height / 2.0 + dy);
            map.center = map.toCoordinate(mapCenterPoint);

            lastX = -1;
            lastY = -1;
        }
    }
}
