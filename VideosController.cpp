//
// Created by derek on 23/05/2026.
//

#include "VideosController.h"

VideosController::VideosController(std::shared_ptr<List<Video>> videoList): videoList(videoList) {}

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