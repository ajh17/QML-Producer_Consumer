/*global Qt,Component,appWindow,Consumer,consumer*/
"use strict";

function createBox() {
    var component = Qt.createComponent("qml/Life/Box.qml"),
        xVal      = Math.floor(Math.random() * 420 + 50),
        yVal      = Math.floor(Math.random() * 420 + 50),
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
    console.log("Error loading the box:", component.errorString());
    return 2;
}

function destroyItem(itemID) {
    console.log("destroyed " + itemID);
    itemID.destroy();
}

// Destroys boxes on contact.
function destroyUponCollision(parentID) {
    var logString = "",
        childrenList  = parentID.children,
        rect          = childrenList[0],
        firstBox,
        secondBox,
        i,
        j,
        ix,
        jx,
        iy,
        jy;

    for (i = 0; i < childrenList.length; i++) {
        for (j = 0; j < childrenList.length; j++) {
            firstBox = childrenList[i];
            secondBox = childrenList[j];
            if (firstBox !== secondBox && (firstBox !== rect && secondBox !== rect)) {
                ix = firstBox.x;
                iy = firstBox.y;
                jx = secondBox.x;
                jy = secondBox.y;

                if (Math.abs(ix - jx) <= 50 && Math.abs(iy - jy) <= 50) {
                    logString += "<<***>> " + firstBox + " (" +  Math.floor(firstBox.x);
                    logString += ", " + Math.floor(firstBox.y);
                    logString += ") and " + secondBox + " (" + Math.floor(secondBox.x);
                    logString += ", " + Math.floor(secondBox.y) + ") have collided.\n";
                    console.log(logString);

                    consumer.consumeSlot(firstBox);
                }
            }
        }
    }
}

function getNewVal(oldVal) {
    var newVal = Math.floor(Math.random() * 420 + 50);
    if (newVal !== oldVal) {
        return newVal;
    }
    return getNewVal(oldVal);
}
