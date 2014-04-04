import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Helper

Rectangle {
    id: appWindow

    signal switchTranslation();

    function callCreate() {
        var box = Helper.createBox();
        return box;
    }

    function quit() {
        console.log("Quitting App!");
        Qt.quit();
    }

    function consumedSlot(anObj) {
        seq1.restart()
        Helper.destroyItem(anObj);
    }

    function collisionSlot(anObj) {
        seq2.restart()
        Helper.destroyItem(anObj);
    }

    // Switch Translation Buttons {{{1
    Row {
        x: 100; y: 5
        spacing: 2
        Button { lang: "English"; onButtonClicked: translation.selectLanguage("en") }
        Button { lang: "French"; onButtonClicked: translation.selectLanguage("fr") }
    }
    // }}}2
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
            text: qsTr("Consumer") + translation.emptyString
            color: "#000"
        }

        SequentialAnimation {
            id: seq1
            running: false
            ColorAnimation {
                id: consumeColorAnimation
                target: consumerTextBox
                property: "color"
                to: "red"; duration: 100
                // onStopped: clearColorConsumer.start()
            }

            ColorAnimation {
                id: clearColorConsumer
                target: consumerTextBox
                property: "color"
                to: "white"; duration: 5000
            }
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
            text: qsTr("Collision Detected: ") + translation.emptyString
            color: "#000"
        }

        SequentialAnimation {
            id: seq2
            running: false
            ColorAnimation {
                id: collisionColorAnimation
                target: collisionTextBox
                property: "color"
                to: "red"; duration: 100
                // onStopped: clearCollisionColor.start()
            }
            ColorAnimation {
                id: clearCollisionColor
                target: collisionTextBox
                property: "color"
                to: "white"; duration: 5000
            }
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
            text: qsTr("Quit App") + translation.emptyString
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
