import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Script

Rectangle {
    id: appWindow

    signal consumeSignal(var anObject);

    signal sendBox(var anObject);

    function callCreate() {
        var box = Script.createBox();
        appWindow.sendBox(box);
        return box;
    }
    function destroyBox(itemID) {
        return Script.destroyItem(itemID);
    }
    function quit() {
        console.log("Quitting App!");
        Qt.quit();
    }

    // Quit Button {{{
    Rectangle {
        width: 75
        height: 25
        x: 200; y: 470; z: 100
        border.width: 1
        border.color: "#000"
        color: "#fff"
        Text {
            anchors.centerIn: parent
            text: "Quit App"
            color: "#000"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: quit()
        }
    }
}
/* vim: set fen fdm=marker : */
