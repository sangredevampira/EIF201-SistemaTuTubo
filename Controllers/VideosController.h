//
// Created by derek on 23/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_VIDEOSCONTROLLER_H
#define PROYECTO_2___KRIS_Y_DEREK_VIDEOSCONTROLLER_H

#include "../Iterator/List.h"
#include "../Adapter/Video.h"
#include "../Exceptions/DuplicateVideo.h"

class VideosController {
private:
    std::shared_ptr<ListInterface<Video>> videoList;
public:
    VideosController();
    std::shared_ptr<Video> searchVideoName(std::string name);
    std::string addVideo(std::shared_ptr<Video> newVideo);
    std::shared_ptr<ListInterface<Video>> getVideoList();
};


#endif //PROYECTO_2___KRIS_Y_DEREK_VIDEOSCONTROLLER_H