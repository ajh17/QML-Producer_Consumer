import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Helper

Rectangle {
    id: appWindow

    function callCreate() {
        var box = Helper.createBox();
        return box;
    }

    function destroyBox(itemID) {
        return Helper.destroyItem(itemID);
    }

    function quit() {
        console.log("Quitting App!");
        Qt.quit();
    }

    Connections {
        target: Consumer
        onConsumedSignal: console.log("!!!!!");
    }

    // Consumer Text Box {{{1
    Rectangle {
        id: consumerTextBox
        objectName: "consumerTextBox"
        width: 75
        height: 25
        x: 5; y: 5; z: 100
        border.width: 1
        border.color: "#000"
        color: "#fff"
        Text {
            anchors.centerIn: parent
            text: qsTr("Consumer")
            color: "#000"
        }
    }

    // Collision Detection Box {{{1
    Rectangle {
        id: collisionTextBox
        objectName: "collisionTextBox"
        width: 125
        height: 25
        x: 370; y: 5; z: 100
        border.width: 1
        border.color: "#000"
        color: "#fff"
        Text {
            anchors.centerIn: parent
            text: qsTr("Collision Detected")
            color: "#000"
        }
    }

    // Quit Button {{{1
    Rectangle {
        width: 75
        height: 25
        x: 200; y: 470; z: 100
        border.width: 1
        border.color: "#000"
        color: "#fff"
        Text {
            anchors.centerIn: parent
            text: qsTr("Quit App")
            color: "#000"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: quit()
        }
    }
    // }}}
}
/* vim: set fen fdm=marker : */
