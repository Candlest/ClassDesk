import QtQuick 2.15
import QtQuick.Window 2.15
import TaoQuick 1.0

Window {
    width: 1240
    height: 480
    visible: true
    title: qsTr("Hello World")
    flags: "SubWindow" // FramelessWindowHint |
    Column {
        anchors.fill: parent
        spacing: 2
        height: splitlineA.height * 2
        width: parent.width
        Rectangle {
            id: splitlineA
            width: parent.width
            height: 10
            color: "#000000"
        }
        //        Rectangle {
        //            id: splitlineB
        //            width: parent.width
        //            height: 10
        //            color: "#123456"
        //        }
        Rectangle {
            height: clock_text.height
            width: parent.width
            id: clock
            Timer {
                id: clock_timer
                running: true
                repeat: true
                triggeredOnStart: true
                onTriggered: {
                    clock_text.text = Qt.formatDateTime(
                                new Date(),
                                "现在是：<font color=\"green\">yyyy/MM/dd<font color=\"green\"> <font color=\"blue\">HH:mm:ss<font color=\"green\">")
                    /*日期显示格式：日后可改*/
                }
            }
            Text {
                anchors.centerIn: parent
                verticalAlignment: Text.AlignVCenter
                textFormat: Text.RichText
                font.pixelSize: 82
                id: clock_text
                text: qsTr("当前时间")
            }
        }

        Row {
            width: parent.width
            height: 400
            CircleProgressBar {
                width: 160
                height: 160
                backgroundColor: "#6495ed"
                NumberAnimation on percent {
                    from: 0
                    to: 70
                    duration: 5000
                    running: true
                    loops: Animation.Infinite
                }
            }
        }
    }
}
