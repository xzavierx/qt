import QtQuick
import QtQuick.Window

Rectangle {
    // 命名为root，不需要指定为字符串
    id: root

    width: 120
    height: 240

    color: "#4A4A4A"

    Image {
        id: triangle
        source: "assets/triangle_red.png"
        // 引用父元素
        x: (parent.width - width) / 2
        y: 40
    }

    Text {
        // 未命名元素

        // 通过id引用元素
        y: triangle.y + triangle.height + 20

        // 引用根元素
        width: root.width

        color: 'white'
        horizontalAlignment: Text.AlignHCenter
        text: qsTr("Triangle")
    }
}
