﻿import QtQuick 2.0

Rectangle {
    width: 136
    height: 120
    color: "red"

    TTextEdit {
        id: input
        x: 8
        y: 8
        width: 120
        height: 104
        focus: true
        text: qsTr("Text Edit")
    }
}