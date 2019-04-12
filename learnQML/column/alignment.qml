import QtQuick 2.0

GreenSquare {
    BlueSquare {
        id: blue1
        width: 48
        height: 24
        y: 8
        anchors.horizontalCenter: parent.horizontalCenter
    }

    BlueSquare {
        id: blue2
        width: 72
        height: 24
        anchors.top: blue1.bottom
        anchors.topMargin: 4
        anchors.horizontalCenter: blue1.horizontalCenter
    }
}
