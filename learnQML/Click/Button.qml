import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Button")

    Rectangle {
        id: button
        x: 12
        y: 12
        width: 116
        height: 16

        color: "lightsteelblue"
        border.color: "slategrey"

        Text {
            id: text
            anchors.centerIn: parent
            text: qsTr("Start")
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                status.text = "Button Clicked"
            }
        }
    }

    Text {
        id: status
        x: 12
        y: 76
        width: 116
        height: 26

        text: qsTr("waiting...")
        horizontalAlignment: Text.AlignHCenter
    }
}
