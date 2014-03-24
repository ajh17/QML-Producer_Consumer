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

// Destroys boxes on contact.
function destroyUponCollision(parentID) {
    var childrenList = parentID.children,
    rect = childrenList[0];
    for (var i in childrenList) {
        for (var j in childrenList) {
            if (childrenList[i] !== childrenList[j]) {
                if (childrenList[i] !== rect && childrenList[j] !== rect) {
                    var ix = childrenList[i].x, iy = childrenList[i].y,
                    jx = childrenList[j].x, jy = childrenList[j].y;

                    if ((Math.abs(ix - jx) <= 50) && (Math.abs(iy - jy) <= 50)) {
                        console.log("TEST ABS: " + Math.abs(iy - jy));
                        console.log("TEST: " + childrenList[i] + "x" + childrenList[i].x);
                        console.log("TEST: " + childrenList[j] + "x" + childrenList[j].x);
                        destroyItem(childrenList[i]);
                        destroyItem(childrenList[j]);
                    }
                }
            }
        }
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
