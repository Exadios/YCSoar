import QtQuick 2.0

Rectangle {
    width: 480
    height: 640

    Text {
        id: preflight
        x: 220
        y: 168
        width: 57
        height: 12
        text: qsTr("Pre Flight")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 18
    }

    Text {
        id: ycsoartitle
        x: 204
        y: 89
        color: "#0000ff"
        text: qsTr("YCSoar")
        font.italic: true
        font.strikeout: false
        font.underline: false
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        styleColor: "#90691d"
        font.pixelSize: 25
    }
}
