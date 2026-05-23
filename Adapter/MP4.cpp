//
// Created by derek on 21/05/2026.
//

#include "MP4.h"

MP4::MP4(std::string name): Video(name) {
}

std::string MP4::play(){
    return "Reproduciendo video: " + videoName;
}

std::string MP4::getVideoName() {
    return videoName;
}
