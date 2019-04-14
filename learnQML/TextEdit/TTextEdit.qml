import QtQuick 2.9
import QtQuick.Window 2.3

FocusScope {
    width: 96
    height: 96
    Rectangle {
        anchors.fill: parent
        color: "blue"
        border.color: "gray"
    }

    property alias text: input.text
    property alias input: input

    TextEdit {
        id: input
        anchors.fill: parent
        anchors.margins: 4
        focus: true
    }
}
