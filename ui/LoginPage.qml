import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    Rectangle { anchors.fill: parent; color: "#F3F6FB" }
    Rectangle {
        width: 400
        height: 440
        radius: 24
        color: "white"
        border.color: "#E2E8F2"
        anchors.centerIn: parent

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 34
            spacing: 14

            Label { text: "✦ NORTHSTAR"; color: "#2764E7"; font.bold: true; font.pixelSize: 15 }
            Label { text: "Welcome back"; color: "#17233C"; font.bold: true; font.pixelSize: 29 }
            Label { text: "Sign in to your demo account"; color: "#7C899E" }
            Item { Layout.preferredHeight: 4 }
            Label { text: "Username"; color: "#34415A" }
            TextField { id: username; Layout.fillWidth: true; text: "demo"; placeholderText: "Username" }
            Label { text: "Password"; color: "#34415A" }
            TextField { id: password; Layout.fillWidth: true; text: "demo123"; placeholderText: "Password"; echoMode: TextInput.Password }
            Label { text: "Demo credentials: demo / demo123"; color: "#7C899E"; font.pixelSize: 12 }
            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 46
                text: "Sign in"
                onClicked: banking.login(username.text, password.text)
                background: Rectangle { radius: 10; color: "#2764E7" }
                contentItem: Label { text: parent.text; color: "white"; font.bold: true; horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter }
            }
            Label { text: banking.message; color: banking.loggedIn ? "#13864F" : "#C43D4B"; wrapMode: Text.Wrap; Layout.fillWidth: true }
        }
    }
}
