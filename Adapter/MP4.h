//
// Created by derek on 21/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_MP4_H
#define PROYECTO_2___KRIS_Y_DEREK_MP4_H

#include "Video.h"
class MP4:public Video{
    public:
    MP4(std::string name = "");
    std::string play() override;
    std::string getVideoName() override;
};


#endif //PROYECTO_2___KRIS_Y_DEREK_MP4_H