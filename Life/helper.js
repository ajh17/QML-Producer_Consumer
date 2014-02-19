var component;
var box;

function createBox() {
    component = Qt.createComponent("qml/Life/Box.qml");
    console.log(component.errorString());
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
            console.log("Creating box at (" + xVal + ", " + yVal + ")");
        }
    }
    else if (component.status === Component.Error) {
        console.log("Error loading the box:", component.errorString());
    }
}

function destroy(itemID) {
    console.log("Destroying box at (" + itemID.x + ", " + itemID.y + ")");
    itemID.destroy();
}
