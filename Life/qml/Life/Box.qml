import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Script

Rectangle {
    id: rectID
    objectName: "box"
    width: 20; height: 20
    color: "#fff"
    border.color: "#000"
    border.width: 1
    MouseArea {
        anchors.fill: parent
        onClicked: Script.destroy(rectID)
    }
}
