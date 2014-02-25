import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/helper.js" as Script

Rectangle {
    id: appWindow

    signal qmlSignal(var anObject);

    function callCreate() {
        return Script.createBox();
    }
    function destroyBox(itemID) {
        return Script.destroyItem(itemID);
    }
}
