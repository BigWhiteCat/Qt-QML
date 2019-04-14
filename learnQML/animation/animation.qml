import QtQuick 2.9
import QtQuick.Window 2.3

Image {
    source: "./assets/background.png"
    width: 900
    height: 400

    Image {
        x: 40
        y: 80
        source: "./assets/rocket.png"

        NumberAnimation on x {
            to: 240
            duration: 4000
            loops: Animation.Infinite
        }
        RotationAnimation on rotation {
            to: 360
            duration: 4000
            loops: Animation.Infinite
        }
    }
}
