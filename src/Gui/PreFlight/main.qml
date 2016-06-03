import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow
  {
  visible: true
  width: 640
  height: 480
  title: qsTr("Pre Flight")

  menuBar: MenuBar
    {
    Menu
      {
      title: qsTr("File")
      MenuItem 
        {
        text: qsTr("&Open")
        onTriggered: console.log("Open action triggered");
        }
      MenuItem 
        {
        text: qsTr("Exit")
        onTriggered: Qt.quit();
        }
      }
    Menu
      {
      title: qsTr("Edit")
      MenuItem
        {
        text: qsTr("Task ...")
        TaskPage
          {
          style: Qt.ScrollBarAsNeeded
          }
        }
      MenuSeparator
        {
        }
      MenuItem
        {
        text: qsTr("Preferences")
        onTriggered: console.log("Preferences action triggered")
        }
      }
    Menu
      {
      title: qsTr("Tools")
      MenuItem
        {
        text: qsTr("Download Map")
        onTriggered: console.log("Download Map action triggered")
        }
      }
    }
  }
