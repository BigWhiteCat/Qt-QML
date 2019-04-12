import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Text Element")

    Text {
        id: textId
        color: "#1e7be4"

        x: (parent.width - width) / 2.0 + parent.x

        // y: (parent.height - height) / 2.0 + parent.y
        text: qsTr("I am learning QML.")
        font.family: "Sans Serif"
        font.pixelSize: 24

        horizontalAlignment: Text.Center
        verticalAlignment: Text.Center
    }
}
