import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 30
        spacing: 22

        RowLayout {
            Layout.fillWidth: true
            ColumnLayout {
                spacing: 4
                Label { text: "Good day, Alex"; font.pixelSize: 28; font.bold: true; color: "#17233C" }
                Label { text: "Here is your account overview."; color: "#7C899E" }
            }
            Item { Layout.fillWidth: true }
            Button { text: "Sign out"; onClicked: banking.logout() }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 190
            radius: 20
            color: "#245CE5"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 26
                spacing: 12
                Label { text: "AVAILABLE BALANCE"; color: "#DCE7FF"; font.pixelSize: 13 }
                Label { text: "$" + banking.balance.toLocaleString(Qt.locale("en_US"), "f", 2); color: "white"; font.pixelSize: 38; font.bold: true }
                Label { text: "Checking account  •••• 2048"; color: "#DCE7FF" }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 260
            radius: 18
            color: "white"
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 24
                spacing: 14
                Label { text: "Quick actions"; font.pixelSize: 20; font.bold: true; color: "#17233C" }
                Label { text: "Amount (USD)"; color: "#46536B" }
                TextField {
                    id: amountField
                    Layout.fillWidth: true
                    placeholderText: "Enter amount, e.g. 25.00"
                    validator: DoubleValidator { bottom: 0.01; decimals: 2; notation: DoubleValidator.StandardNotation }
                }
                RowLayout {
                    Layout.fillWidth: true
                    Button {
                        Layout.fillWidth: true
                        text: "＋ Deposit"
                        onClicked: {
                            if (banking.deposit(Number(amountField.text))) amountField.clear()
                        }
                    }
                    Button {
                        Layout.fillWidth: true
                        text: "− Withdraw"
                        onClicked: {
                            if (banking.withdraw(Number(amountField.text))) amountField.clear()
                        }
                    }
                }
                Label { text: banking.message; color: banking.message.startsWith("Deposit") || banking.message.startsWith("Withdrawal") ? "#13864F" : "#66748B"; wrapMode: Text.Wrap; Layout.fillWidth: true }
            }
        }

        Label {
            text: "Portfolio demo only — no real bank connection or money movement."
            color: "#8A96AA"
            font.pixelSize: 12
            wrapMode: Text.Wrap
        }
    }
}
