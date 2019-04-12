import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Image {
        id: image1
        source: "/home/xiaohai/Pictures/flower.jpg"
        x: 12
        y: 12

        width: 100
        height: 100
    }

    Image {
        id: image2
        source: "/home/xiaohai/Pictures/flower.jpg"

        x: 120
        y: 120

        width: 100
        height: 100

        fillMode: Image.PreserveAspectCrop

        clip: true
    }
}
