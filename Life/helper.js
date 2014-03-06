function createBox() {
    "use strict";
    var component = Qt.createComponent("qml/Life/Box.qml"),
    xVal = Math.floor((Math.random() * 420) + 1),
    yVal = Math.floor((Math.random() * 420) + 1), box;

    if (component.status === Component.Ready) {
        box = component.createObject(appWindow, { "x": xVal, "y": yVal });
        if (box === null) {
            console.log("Error creating the box");
        }
        else {
            console.log("Created " + box + "(" + xVal + ", " + yVal + ")");
            return box;
        }
        return 0;
    }
    else if (component.status === Component.Error) {
        console.log("Error loading the box:", component.errorString());
    }
}

function destroyItem(itemID) {
    console.log("Destroyed " + itemID);
    itemID.destroy();
}

function moveBox(itemID) {
    console.log("Moving box " + itemID);
    var xVal = Math.floor((Math.random() * 420) + 1);
    var yVal = Math.floor((Math.random() * 420) + 1);

    itemID.x = xVal;
    itemID.y = yVal;

    return itemID;
}
