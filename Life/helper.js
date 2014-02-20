var component;
var box;

function createBox() {
    component = Qt.createComponent("qml/Life/Box.qml");
    console.log(component.errorString());
    if (component.status === Component.Ready) {
        box = component.createObject(appWindow, { "x": xVal, "y": yVal });
        console.log("Creating box at (" + xVal + ", " + yVal + ")");
        return box;
    }
    else {
        console.log("Something broke.");
    }
}

function destroyRect() {
    if (!box) {
        box.destroy();
    }
}
