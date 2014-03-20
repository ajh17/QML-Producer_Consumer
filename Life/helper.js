function createBox() {
    var component = Qt.createComponent("qml/Life/Box.qml");
    var xVal = Math.floor((Math.random() * 420) + 1);
    var yVal = Math.floor((Math.random() * 420) + 1);
    var box;

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
        return 0;
    }
}

function destroyItem(itemID) {
    console.log("Destroyed " + itemID);
    itemID.destroy();
}

function destroyUponCollision(parentID) {
    for (var i = 1; i < children.length; ++i) {
        console.log("hello! " + children[i]);
    }
}

function getNewVal(oldVal) {
    var newVal = Math.floor((Math.random() * 420) + 1);
    if (newVal === oldVal) {
        getNewVal(oldVal);
    }
    else {
        return newVal;
    }
}
