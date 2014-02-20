import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Script

Rectangle {
    id: appWindow
    function callCreate() {
        Script.createBox();
        return 0;
    }
    function destroyBox() {
        Script.destroyRect();
        return 0;
    }
}
