import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800;
    height: 600;

    Component.onCompleted: {
        //idMainForm.textScore.text = ccScore.score

    }

    Connections {
        target: ccManager
        onStateChanged: {
            if(state) {

              //idMainForm.textScore.text = "hit!"
            } else {
                //idMainForm.textScore.text = "miss"
            }
        }

        onClickHandled: {

        }




    }



    MainForm {
        id: idMainForm;
        anchors.fill: parent;
        buttonNewGame.onClicked: {
            ccManager.newGame()
        }
        mouseArea.onClicked: {
             ccManager.reportClick(new Date().getMilliseconds())
        }
    }
}

