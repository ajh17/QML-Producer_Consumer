var component;
var box;

function createBox() {
    component = Qt.createComponent("qml/Life/Box.qml");
    var xVal = Math.floor((Math.random() * 500) + 1);
    var yVal = Math.floor((Math.random() * 500) + 1);

    if (component.status === Component.Ready) {
        finishCreation();
    }
    else {
        component.statusChanged.connect(finishCreation);
    }
}

function finishCreation() {
    var xVal = Math.floor((Math.random() * 500) + 1);
    var yVal = Math.floor((Math.random() * 500) + 1);

    if (component.status === Component.Ready) {
        box = component.createObject(appWindow, { "x": xVal, "y": yVal });
        if (box === null) {
            console.log("Error creating the box");
        }
        else {
            console.log("Creating" + box + "(" + xVal + ", " + yVal + ")");
        }
    }
    else if (component.status === Component.Error) {
        console.log("Error loading the box:", component.errorString());
    }
}

function destroyRect() {
    var itemID = "rectID";
    console.log("Destroying box at (" + itemID.x + ", " + itemID.y + ")");
    itemID.destroy();
}
