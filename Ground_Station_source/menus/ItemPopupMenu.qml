import QtQuick 2.12
import QtQuick.Controls 1.4

Menu {
    property var type
    signal itemClicked(string item)

    function update() {
        clear()
        addItem(qsTr("Info")).triggered.connect(function(){itemClicked("show" + type + "Info")})
        addItem(qsTr("Delete")).triggered.connect(function(){itemClicked("delete" + type )})
    }
}
