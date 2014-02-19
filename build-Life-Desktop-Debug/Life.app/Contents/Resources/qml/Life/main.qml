import QtQuick 2.0

Item {
    id: grid
    color: "black";
    function test(msg) {
        console.log("Got msg: ", msg);
        grid.color = "white";
        return 0;
    }

    Box {
        objectName: "box1"
        x: 0; y: 0
    }
    Box {
        objectName: "box2"
        x: 20; y: 0
    }
    Box {
        objectName: "box3"
        x: 40; y: 0
    }
    Box {
        objectName: "box4"
        x: 60; y: 0
    }
    Box {
        objectName: "box5"
        x: 80; y: 0
    }
    Box {
        objectName: "box6"
        x: 100; y: 0
    }
}
