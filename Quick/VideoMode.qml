import QtQuick 2.15
import QtMultimedia 5.0

Item {
    anchors.fill: parent
    MediaPlayer {
        id: media
        autoPlay: true
        source: "file:///" + appDir + "/video.mp4"
        loops: 0
    }
    VideoOutput{
            anchors.fill: parent;
            source: media;
            //flushMode: VideoOutput.LastFrame;
    }
}
