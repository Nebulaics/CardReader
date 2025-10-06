import QtQuick
import CardReader

Window {
    id: mainApplication

    width: mainScreen.width
    height: mainScreen.height

    objectName: "MyApp"

    signal cardData(string value)

    visible: true
    title: "CardReader"

    Component.onCompleted: {
        mainApplication.requestActivate()
    }

    Screen01 {
        id: mainScreen

        Component.onCompleted: {
            mainScreen.cardInput.forceActiveFocus()
        }


        Keys.onReturnPressed: {
            console.log(mainScreen.cardInput.text)
            cardData(mainScreen.cardInput.text)

            mainScreen.cardInput.text = ""

            console.log("cardData signal sent")
        }
    }

}

