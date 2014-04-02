import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Helper

Rectangle {
    id: appWindow

    function callCreate() {
        var box = Helper.createBox();
        return box;
    }

    function quit() {
        console.log("Quitting App!");
        Qt.quit();
    }

    function consumedSlot(anObj) {
        consumeColorAnimation.start()
        Helper.destroyItem(anObj);
        // consumeColorAnimation.stop()
    }

    function collisionSlot(anObj) {
        collisionColorAnimation.start();
        Helper.destroyItem(anObj);
        // collisionColorAnimation.stop();
    }

    function clearSlot() {
        clearColorConsumer.start();
        clearColorCollision.start();
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
        color: "white"
        Text {
            anchors.centerIn: parent
            text: qsTr("Consumer")
            color: "#000"
        }

        ColorAnimation on color {
            id: consumeColorAnimation
            running: false
            to: "red"; duration: 100
        }

        ColorAnimation on color {
            id: clearColorConsumer
            running: false
            to: "white"; duration: 100
        }
    }

    // Collision Detection Box {{{1
    Rectangle {
        id: collisionTextBox
        objectName: "collisionTextBox"
        width: 135
        height: 25
        x: 360; y: 5; z: 100
        border.width: 1
        border.color: "#000"
        color: "white"
        Text {
            id: collisionText
            anchors.centerIn: parent
            text: qsTr("Collision Detected: ")
            color: "#000"
        }

        ColorAnimation on color {
            id: collisionColorAnimation
            running: false
            to: "red"; duration: 100
        }

        ColorAnimation on color {
            id: clearColorCollision
            running: false
            to: "white"; duration: 100
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
