import QtQuick 2.0

Item {
    function test() {
        console.log("Got msg: ");
        return 0;
    }

    id: grid
    Box { objectName: "testing"; id: box1; x: 0; y: 0 }
    Box { id: box2; x: 20; y: 0 }
    Box { id: box3; x: 40; y: 0 }
    Box { id: box4; x: 60; y: 0 }
    Box { id: box5; x: 80; y: 0 }
    Box { id: box6; x: 100; y: 0 }
}
