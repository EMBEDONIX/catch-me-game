import QtQuick 2.5
import QtQuick.Controls 1.3

Rectangle {
    id: idAppMainWindow

    property alias textScore: idTextScore
    property alias mouseArea: idMouseArea
    property alias buttonNewGame: idButtonNewGame

    width: 800
    height: 600
    color:  "transparent"
    radius: 0
    border.width: 0

    Column {
        id: idAppMainColumn
        x: 0
        y: 0
        width: 800
        height: 600


        Row {
            id: idMainRowInfo
            width: 800
            height: 100
            clip: false

            Flow {
                id: idMainRowInfoFlow
                width: 800
                height: 100
            }
        }

        Row {
            id: idMainRowGameContainer
            width: 800
            height: 500
        }
    }

    Label {
        id: idTextScore
        x: 30
        y: 46
        text: ccManager.scoreSystem.score;
    }

    Button {
        id: idButtonNewGame
        x: 678
        y: 42
        text: qsTr("New Game")
    }

    MouseArea {
        id: idMouseArea
        x: 8
        y: 111
        width: 784
        height: 481
    }
}

