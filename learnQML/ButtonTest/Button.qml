import QtQuick 2.0

Rectangle {
    id: root

    property alias text: label.text
    signal clicked

    Text {
        id: label
        text: qsTr("Start")
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
