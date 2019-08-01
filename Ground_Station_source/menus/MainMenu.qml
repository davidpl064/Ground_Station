import QtQuick 2.12
import QtQuick.Controls 1.4
import QtLocation 5.11

MenuBar {
    property var  providerMenu: providerMenu
    property var  mapTypeMenu: mapTypeMenu
    property var  toolsMenu: toolsMenu
    property alias isFollowMe: toolsMenu.isFollowMe
    property alias isMiniMap: toolsMenu.isMiniMap

    signal selectProvider(string providerName)
    signal selectMapType(variant mapType)
    signal selectTool(string tool);
    signal toggleMapState(string state)

    Menu {
        id: providerMenu
        title: qsTr("Provider")

        function createMenu(plugins)
        {
            clear()
            for (var i = 0; i < plugins.length; i++) {
                createProviderMenuItem(plugins[i]);
            }
        }

        function createProviderMenuItem(provider)
        {
            var item = addItem(provider);
            item.checkable = true;
            item.triggered.connect(function(){selectProvider(provider)})
        }
    }

    Menu {
        id: mapTypeMenu
        title: qsTr("MapType")

        function createMenu(map)
        {
            clear()
            for (var i = 0; i < map.supportedMapTypes.length; i++) {
                createMapTypeMenuItem(map.supportedMapTypes[i]).checked =
                        (map.activeMapType === map.supportedMapTypes[i]);
            }
        }

        function createMapTypeMenuItem(mapType)
        {
            var item = addItem(mapType.name);
            item.checkable = true;
            item.triggered.connect(function(){selectMapType(mapType)})
            return item;
        }
    }

    Menu {
        id: toolsMenu
        property bool isFollowMe: false;
        property bool isMiniMap: false;
        title: qsTr("Tools")

        function createMenu(map)
        {
            clear()
            if (map.plugin.supportsGeocoding(Plugin.ReverseGeocodingFeature)) {
                addItem(qsTr("Reverse geocode")).triggered.connect(function(){selectTool("RevGeocode")})
            }
            if (map.plugin.supportsGeocoding()) {
                addItem(qsTr("Geocode")).triggered.connect(function(){selectTool("Geocode")})
            }
            if (map.plugin.supportsRouting()) {
                addItem(qsTr("Route with coordinates")).triggered.connect(function(){selectTool("CoordinateRoute")})
                addItem(qsTr("Route with address")).triggered.connect(function(){selectTool("AddressRoute")})
            }

            var item = addItem("")
            item.text = Qt.binding(function() { return isMiniMap ? qsTr("Hide minimap") : qsTr("Minimap") })
            item.triggered.connect(function() {toggleMapState("MiniMap")})

            item = addItem("")
            item.text = Qt.binding(function() { return isFollowMe ? qsTr("Stop following") : qsTr("Follow me")})
            item.triggered.connect(function() {toggleMapState("FollowMe")})

            addItem(qsTr("Language")).triggered.connect(function(){selectTool("Language")})
            addItem(qsTr("Prefetch Map Data")).triggered.connect(function(){selectTool("Prefetch")})
            addItem(qsTr("Clear Map Data")).triggered.connect(function(){selectTool("Clear")})
        }
    }
}
