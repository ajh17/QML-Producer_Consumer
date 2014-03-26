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
    var logString = "";
    var childrenList = parentID.children;
    for (var i in childrenList) {
        for (var j in childrenList) {
            var firstBox = childrenList[i], secondBox = childrenList[j];
            if (firstBox !== secondBox) {
                if (firstBox !== rect && secondBox !== rect) {
                    var ix = firstBox.x, iy = firstBox.y,
                    jx = secondBox.x, jy = secondBox.y;

                    if ((Math.abs(ix - jx) <= 50) && (Math.abs(iy - jy) <= 50)) {
                        logString += "<<***>> " + firstBox + " (" +  firstBox.x + "," + firstBox.y;
                        logString += ") and " + secondBox + " (" + firstBox.x + "," , + firstBox.y;
                        logString += ") have collided.\n";
                        console.log(logString);

                        destroyItem(firstBox);
                        destroyItem(secondBox);
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
