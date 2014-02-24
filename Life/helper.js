var component;
var box;

function createBox() {
    component = Qt.createComponent("qml/Life/Box.qml");
    var xVal = Math.floor((Math.random() * 500) + 1);
    var yVal = Math.floor((Math.random() * 500) + 1);

    if (component.status === Component.Ready) {
        box = component.createObject(appWindow, { "x": xVal, "y": yVal });
        console.log("Creating box at (" + xVal + ", " + yVal + ")");
        console.log(box);
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
