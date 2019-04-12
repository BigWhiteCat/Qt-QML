import QtQuick 2.10
import QtQuick.Window 2.10

Rectangle {
    id: root

    width: 120
    height: 240

    color: "#D8D8D8"

    Image {
        id: rocket
        x: (parent.width - width) / 2
        y: 40
        source: "images/flower.jpg"
    }

    Text {
        y: rocket.y + rocket.height + 20
        width: root.width
        color: "#2fb584"
        text: qsTr("Flow")
        horizontalAlignment: Text.AlignHCenter
    }
}
