import QtQuick 2.10
import QtQuick.Window 2.10

Rectangle {
    width: 200
    height: 80
    color: "linen"

    TextInput {
        id: input1
        x: 8
        y: 8
        width: 96
        height: 20
        color: "red"
        focus: true
        text: qsTr("Text Input 1")
    }

    TextInput {
        id: input2
        x: 8
        y: 36
        width: 96
        height: 20
        color: "red"
        text: qsTr("Text Input 2")
    }
}
