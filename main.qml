import QtQuick 2.5
import QtQuick.Window 2.2


Window {
    visible: true
    width: 300;
    height: 300;
    property int receivedTime: 0;

    MainForm {
        id: idMainForm;
        anchors.fill: parent;

        property var blocks: [];

        buttonNewGame.onClicked: {
            for(var i = 0; i < blocks.length; i++) {
                blocks[i].destroy();
            }

            blocks = [];
            ccManager.newGame()
        }
        Connections {
            target: ccManager
            onSpriteRequested: {

                console.log("onSpriteRequested")
                createRect(idMainForm.rowGameArea);
            }

            onClickHandled: {
                console.log("onClickHandled -> result = " + result
                            + " id = " + id)

                if(result) {
                    makeBlue(id);
                } else {
                    makeRed(id);
                }
            }
        }
    }


    /******* FUNCTIONS *********/
    //TODO move to js file

    function createRect(parent)
    {
          var component = Qt.createComponent("sprite_small.qml");
        if( component.status !== Component.Ready )
        {
            if( component.status === Component.Error )
                console.debug("Error:"+ component.errorString() );
            return; // or maybe throw
        }

          var rect = component.createObject(parent,{"x":50,"y":10});
          if(rect !== null ) {
              rect.index = idMainForm.blocks.length + 1;
              rect.creationTime = new Date();
              rect.x =  Math.floor(Math.random() * 300 );
              rect.y = Math.floor(Math.random() * 230 );
              idMainForm.blocks.push(rect);
              //rect.dropped.connect(dropped);
        }
    }

    function makeBlue(id) {
        var item = idMainForm.blocks[id - 1];
        item.color = "blue";
        item.clickable = false;
    }

    function makeRed(id) {
        var item = idMainForm.blocks[id - 1];
        item.color = "red";
        item.clickable = false;
    }
}

