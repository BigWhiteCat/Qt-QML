import QtQuick 2.9

DarkSquare {
    id: root
    width: 120
    height: 240

    // 将其子元素从上到下排列
    Column {
        id: column
        anchors.centerIn: parent
        spacing: 8
        RedSquare {
        }

        GreenSquare {
            width: 96
        }

        BlueSquare {
        }
    }
}
