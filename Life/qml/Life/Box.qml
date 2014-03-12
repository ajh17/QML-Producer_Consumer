import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Script

Rectangle {
    id: rectID
    objectName: "box"
    width: 20; height: 20
    color: Qt.rgba(0, 0, 1)
    border.color: "#000"
    border.width: 1

    SequentialAnimation on x {
        loops: Animation.Infinite
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
        PropertyAnimation { to: Script.getNewVal(x); }
    }

    SequentialAnimation on y {
        loops: Animation.Infinite
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
        PropertyAnimation { to: Script.getNewVal(y); }
    }
}
