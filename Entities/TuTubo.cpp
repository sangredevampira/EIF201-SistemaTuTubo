//
// Created by derek on 25/05/2026.
//

#include "TuTubo.h"

TuTubo::TuTubo(){
    activeSession = nullptr;
    channelsManagement = std::make_shared<ChannelsController>();
    videosManagement = std::make_shared<VideosController>();
}

void TuTubo::setActiveSession(std::shared_ptr<Channel>) {
}

std::string TuTubo::createUser(std::string, std::string, std::string) {
}

std::shared_ptr<Channel> TuTubo::login(std::string, std::string) {
}

std::string TuTubo::uploadVideo(std::string) {
}

std::string TuTubo::suscribeToChannel(std::string) {
}

std::string TuTubo::unsuscribeFromChannel(std::string) {
}

std::string TuTubo::searchVideoByTitle(std::string title) {
    std::stringstream s;

    if (videosManagement == nullptr) {
        throw VideosNotAvailable();
    }
    auto video = videosManagement->searchVideoName(title);

    if (video == nullptr) {
        throw MissingVideo();
    }

    s << "Video encontrado exitosamente: " << video->getVideoName();

    return s.str();
}

std::string TuTubo::searchVideoByChannel(std::string, std::string) {
}

std::string TuTubo::playVideo(std::shared_ptr<Video>) {
}
