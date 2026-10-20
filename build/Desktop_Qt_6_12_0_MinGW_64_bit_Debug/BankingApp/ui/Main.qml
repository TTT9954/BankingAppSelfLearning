import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 1000
    height: 700
    minimumWidth: 760
    minimumHeight: 560
    title: "Northstar Banking"
    color: "#F3F6FB"

    StackLayout {
        anchors.fill: parent
        currentIndex: banking.loggedIn ? 1 : 0
        LoginPage {}
        DashboardPage {}
    }
}
