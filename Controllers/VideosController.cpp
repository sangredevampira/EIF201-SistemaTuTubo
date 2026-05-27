//
// Created by derek on 23/05/2026.
//

#include "VideosController.h"

VideosController::VideosController()
{ videoList = std::make_shared<List<Video>>(); }

std::shared_ptr<Video> VideosController::searchVideoName(std::string name) {
    if (videoList->isEmpty()) {
        return nullptr;
    }
    auto iterator = videoList->createIterator();
    while (iterator->hasNext()) {
        auto video = iterator->getNext();
        if (video->getVideoName() == name) {
            return video;
        }
    }
    return nullptr;
}