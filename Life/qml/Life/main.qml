import QtQuick 2.0
import "/Users/ajh/Developer/Cpp/QML/Life/Life/createboxes.js" as Script

Item {
    id: itemID
    function callCreate() {
        Script.createBox();
        return 0;
    }
}
