

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
    id: cluster
    width: Constants.width
    height: Constants.height

    property alias cardInput: textInput

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
            y: 281
            width: 1024
            height: 159
            color: "#ffffff"
            text: qsTr("Swipe Your Card")
            font.pixelSize: 140
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: placeholderText
            x: 280
            y: 493
            width: 465
            height: 114
            color: "#ffffff"
            text: qsTr("Swipe Card")
            font.pixelSize: 100
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            visible: textInput.text.length === 0
        }

        TextInput {
            id: textInput
            x: 280
            y: 493
            width: 465
            height: 114
            color: "#ffffff"
            font.pixelSize: 100
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            visible: false
        }
    }

    states: [
        State {
            name: "clicked"
        }
    ]
}
