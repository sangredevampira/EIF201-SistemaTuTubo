//
// Created by derek on 23/05/2026.
//

#include "VideosController.h"

#include "../Exceptions/DuplicateVideo.h"
#include "../Exceptions/VideosNotAvailable.h"

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

std::string VideosController::addVideo(std::shared_ptr<Video> newVideo) {

    std::stringstream s;
    if (newVideo == nullptr) {
        throw VideosNotAvailable();
    }

    auto iterator = videoList->createIterator();
    while (iterator->hasNext()) {
        auto currentVideo = iterator->getNext();
        if (currentVideo->getVideoName() == newVideo->getVideoName()) {
            throw DuplicateVideo();
        }
    }

    videoList->insertFirst(newVideo);
    s << "Video agregado a la lista general.";

    return s.str();
}

std::shared_ptr<ListInterface<Video>> VideosController::getVideoList() {
    return videoList;
}
