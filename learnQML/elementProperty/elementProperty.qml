import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Element Properties")

    Text {
        id: thisLabel

        x: 24
        y: 16

        height: 2 * width

        property int times: 24
        property alias anotherTimes: thisLabel.times

        text: qsTr("text") + times
        font.family: "Serif"
        font.pixelSize: 24

        onHeightChanged: console.log("height: ", height)

        //        focus: true
        color: focus ? "red" : "blue"
    }
}
