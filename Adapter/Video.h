//
// Created by derek on 21/05/2026.
//

#ifndef PROYECTO_2_KRIS_Y_DEREK_VIDEO_H
#define PROYECTO_2_KRIS_Y_DEREK_VIDEO_H

#include "../Utilities/Utilities.h"
class Video
{
    protected:
    std::string videoName;
    public:
    Video(std::string name = "");
    virtual std::string getVideoName() = 0;
    virtual std::string play() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Video& video);
};
std::ostream& operator<<(std::ostream& os, const Video& video);
#endif //PROYECTO_2_KRIS_Y_DEREK_VIDEO_H