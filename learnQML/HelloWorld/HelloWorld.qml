import QtQuick 2.9
import QtQuick.Window 2.3

Rectangle {
    width: 360
    height: 360
    Text {
        anchors.centerIn: parent
        text: qsTr("Hello World")
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit()
        }
    }
}
