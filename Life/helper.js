function createBox() {
    var component;
    var box;

    component = Qt.createComponent("Box.qml");
    if (component.status === Component.Ready) {
        finishCreation();
    }
}

function finishCreation() {
    if (component.status === Component.Ready) {
        box = component.createObject(appWindow, { "x": 10, "y": 10 });
    }
    return 0;
}
