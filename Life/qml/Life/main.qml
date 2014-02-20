import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Script

Rectangle {
    id: appWindow
    function callCreate() {
        return Script.createBox();
    }
    function destroyBox() {
        Script.destroyRect();
    }
}
