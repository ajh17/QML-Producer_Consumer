import QtQuick 2.0

Rectangle {
    id: button;
    property string lang;

    signal buttonClicked()

    width: 120
    height: 25
    color: mouseArea.pressed ? "lightgray" : "white"
    radius: 5
    border.width: 1; border.color: "black"

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.buttonClicked();
    }
    Text {
        anchors.centerIn: parent
        text: button.lang
    }
}
