import QtQuick 2.5
import QtQuick.Controls 1.4

import "qrc:/components" as C
import "qrc:/components/functions.js" as JS

ApplicationWindow {
    id:root
    width: 800; height: 600
    visible: true
    property var accentColor : "#03A9F4"
    property var darkPrimaryColor : "#5D4037"
    property var primaryColor : "#795548"
    property var darkTextColor : "#212121"
    property var lightTextColor : "#FFF"
    C.Frame {
        topBarHeightPercent:5
        bottomBarHeightPercent:5
        topBarColor:primaryColor
        bottomBarColor:primaryColor
        topBarContent:Item {
            anchors { fill: parent; margins: JS.hpercent(5,parent) }
            Row {
                anchors.fill: parent
                C.ImageButton {
                    id:returnBtn
                    visible: !_fileManager.current.isRoot
                    height: JS.hpercent(100,parent); width: height
                    color: "transparent"
                    source: "https://cdn4.iconfinder.com/data/icons/pictype-free-vector-icons/16/back-48.png"
                    action.onClicked: {
                        _fileManager.cdUp()
                    }
                }
            }
        }

        content: GridView {
            id:grid
            property int columns: 6
            property int rows: 7
            property var spacing : JS.hpercent(2,parent)
            property var margin : JS.hpercent(1,parent)
            anchors { fill:parent; margins: margin; leftMargin: margin+spacing/2; topMargin: margin+spacing/2; }
            model: _fileManager.current.content;
            cellWidth: JS.wpercent(100/columns,this)
            cellHeight: JS.hpercent(100/rows,this)
            delegate: Rectangle {
                height:grid.cellHeight-grid.spacing/2; width: grid.cellWidth-grid.spacing/2
                color: isDir ? accentColor : "#BBB"
                radius: JS.wpercent(10,this)
                TextArea {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    font.pixelSize: JS.hpercent(20,parent)
                    textColor: isDir ? lightTextColor : darkTextColor
                    backgroundVisible: false
                    frameVisible: false
                    readOnly: true
                    text:name
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if(isDir)
                            _fileManager.cd(name)
                        else
                            _fileManager.openFile(name)
                    }
                }
            }
        }

        bottomBarContent: Item {
            anchors { fill:parent; margins: JS.hpercent(10,parent) }
            Row {
                anchors.fill: parent
                Text {
                    id:statusBarText
                    height: JS.hpercent(100,parent); width: JS.wpercent(60,parent)
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: JS.hpercent(50,this)
                    color:lightTextColor
                    text:"Status Bar"
                }
            }
        }
    }
    Connections {
        target:_fileManager
        onRefreshList: {
            grid.model = _fileManager.current.content
            returnBtn.visible = !_fileManager.current.isRoot
        }
        onUpdateStatusBar: {
            statusBarText.text = message
        }
    }
}

