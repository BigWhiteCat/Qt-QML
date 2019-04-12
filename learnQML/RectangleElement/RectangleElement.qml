import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Rectangle Element")

    Rectangle {
        id: rect1

        x: 12
        y: 12

        width: 76
        height: 96

        color: "lightsteelblue"
    }

    Rectangle {
        id: rect2

        x: 112
        y: 12

        width: 76
        height: 96

        border.color: "lightsteelblue"
        border.width: 4

        radius: 8
    }

    Rectangle {
        id: rect3

        x: rect2.x + rect2.width + 12
        y: 12

        width: 176
        height: 96

        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: "red"
            }
            GradientStop {
                position: 1.0
                color: "blue"
            }
        }

        border.color: "yellow"
    }
}
