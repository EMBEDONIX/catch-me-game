import QtQuick 2.0

Rectangle {
        id: idSmallSprite;
        width:20
        height:20
        color:"green"
        property date creationTime;
        property bool clickable: true;
        property int index: 0;

        MouseArea {
            anchors.fill: parent
            onClicked: {

                if(clickable) {
                    var nowMilli = new Date().getTime();
                    var diff = nowMilli - creationTime.getTime();
                    console.log("Clicked on a block on " + nowMilli
                                + " which was created on " + creationTime.getTime()
                                + " TimeToClick = " + diff + " milliseconds");

                    ccManager.reportClick(diff, index);
                }

            }
        }
}

