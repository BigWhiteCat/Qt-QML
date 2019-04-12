import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Mouse Area")

    Rectangle {
        id: rect1
        x: 12
        y: 12

        width: 76
        height: 96

        color: "blue"

        MouseArea {
            id: mouseArea
            width: parent.width
            height: parent.height

            onClicked: rect2.visible = !rect2.visible
        }

        Rectangle {
            id: rect2
            x: 112
            y: 12

            width: 76
            height: 96

            border.color: "red"
            border.width: 4

            radius: 8
        }
    }
}
