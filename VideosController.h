//
// Created by derek on 23/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_VIDEOSCONTROLLER_H
#define PROYECTO_2___KRIS_Y_DEREK_VIDEOSCONTROLLER_H

#include "List.h"
#include "Adapter/Video.h"
class VideosController {
private:
    std::shared_ptr<List<Video>> videoList;
public:
    VideosController(std::shared_ptr<List<Video>> videoList);
    std::shared_ptr<Video> searchVideoName(std::string name);
};


#endif //PROYECTO_2___KRIS_Y_DEREK_VIDEOSCONTROLLER_H