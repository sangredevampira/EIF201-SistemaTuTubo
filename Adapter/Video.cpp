//
// Created by derek on 21/05/2026.
//
#include "Video.h"

Video::Video(std::string name) {
    this->videoName = name;
}

std::ostream& operator<<(std::ostream& os, const Video& video) {
    os << video.videoName;
    return os;
}