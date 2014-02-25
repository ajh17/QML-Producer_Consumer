function createBox() {
    var component = Qt.createComponent("qml/Life/Box.qml");
    var xVal = Math.floor((Math.random() * 500) + 1);
    var yVal = Math.floor((Math.random() * 500) + 1);

    if (component.status === Component.Ready) {
        var box = component.createObject(appWindow, { "x": xVal, "y": yVal });
        if (box === null) {
            console.log("Error creating the box");
        }
        else {
            console.log("Creating " + box + "(" + xVal + ", " + yVal + ")");
            return box;
        }
        return 0;
    }
    else if (component.status === Component.Error) {
        console.log("Error loading the box:", component.errorString());
    }
}

function destroyItem(itemID) {
    console.log("Destroying " + itemID);
    itemID.destroy();
}
