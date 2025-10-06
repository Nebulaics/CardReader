

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import CardReader

Item {
    id: root
    width: Constants.width
    height: Constants.height

    Image {
        id: bg
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        source: "images/BgWIP.png"
        fillMode: Image.PreserveAspectFit

        Text {
            id: text1
            x: 0
            y: 57
            width: 1024
            height: 93
            color: "#ffffff"
            text: qsTr("Welcome to Banking")
            font.pixelSize: 80
            horizontalAlignment: Text.AlignHCenter
        }
    }

    states: [
        State {
            name: "clicked"
        }
    ]
}
