#pragma once

#include <string>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>

class AudioPlayer {
public:
    bool Init();
    void Play();
    void Stop();.
    void SeekForward();
    void SeekBackward();
    void LoadAudio(const std::string& filePath);
    void Close();

private:
    AVFormatContext* formatContext = nullptr;
    AVCodecContext* codecContext = nullptr;
    AVCodec* codec = nullptr;
    int audioStreamIndex = -1;
};
