#include <ffmpeg/libavutil/log.h>
#include <ffmpeg/libavformat/avformat.h>

int main() {
    av_log_set_level(AV_LOG_INFO);
    avformat_network_init();
    printf("Complete");
    return 0;
}