import QtQuick 2.5
import QtQuick.Controls 1.3

Rectangle {
    id: idAppMainWindow

    property alias textScore: idTextScore
    property alias buttonNewGame: idButtonNewGame
    property alias rowGameArea: idMainRowGameContainer;

    width: 300
    height: 300
    color:  "transparent"
    radius: 0
    border.width: 0

    Column {
        id: idAppMainColumn
        x: 0
        y: 0
        width: 300
        height: 300


        Row {
            id: idMainRowInfo
            width: 300
            height: 50
            clip: false

            Flow {
                id: idMainRowInfoFlow
                width: 300
                height: 50
            }
        }

        Row {
            id: idMainRowGameContainer
            width: 300
            height: 250
        }
    }

    Label {
        id: idTextScore
        x: 8
        y: 8
        text: ccScore.score;
    }

    Button {
        id: idButtonNewGame
        x: 202
        y: 9
        width: 90
        height: 16
        text: qsTr("New Game")
    }
}

