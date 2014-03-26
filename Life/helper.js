function createBox() {
    var component = Qt.createComponent("qml/Life/Box.qml"),
        xVal      = Math.floor((Math.random() * 420) + 1),
        yVal      = Math.floor((Math.random() * 420) + 1),
        box;

    if (component.status === Component.Ready) {
        box = component.createObject(appWindow, { "x": xVal, "y": yVal });
        if (box === null) {
            console.log("Error creating the box");
            return 1;
        }
        console.log("Created " + box + "(" + xVal + ", " + yVal + ")");
        return box;
    }
    else if (component.status === Component.Error) {
        console.log("Error loading the box:", component.errorString());
        return 2;
    }
}

function destroyItem(itemID) {
    console.log("Destroyed " + itemID);
    itemID.destroy();
}

// Destroys boxes on contact.
function destroyUponCollision(parentID) {
    var logString    = "",
        childrenList = parentID.children,
        rect         = childrenList[0];

    for (var i in childrenList) {
        for (var j in childrenList) {
            var firstBox = childrenList[i], secondBox = childrenList[j];
            if (firstBox !== secondBox && (firstBox !== rect && secondBox !== rect)) {
                var ix = firstBox.x,
                    iy = firstBox.y,
                    jx = secondBox.x,
                    jy = secondBox.y;

                if (Math.abs(ix - jx) <= 50 && Math.abs(iy - jy) <= 50) {
                    logString += "<<***>> " + firstBox + " (" +  firstBox.x;
                    logString += "," + firstBox.y;
                    logString += ") and " + secondBox + " (" + firstBox.x;
                    logString += "," + firstBox.y + ") have collided.\n";
                    console.log(logString);

                    parentID.consumeSignal(firstBox);
                    parentID.consumeSignal(secondBox);
                }
            }
        }
    }
}

function getNewVal(oldVal) {
    var newVal = Math.floor((Math.random() * 420) + 1);
    if (newVal !== oldVal) {
        return newVal;
    }
    return getNewVal(oldVal);
}
