//
// Created by derek on 25/05/2026.
//

#include "TuTubo.h"

TuTubo::TuTubo(){
    activeSession = nullptr;
    channelsManagement = std::make_shared<ChannelsController>();
    videosManagement = std::make_shared<VideosController>();
}

void TuTubo::setActiveSession(std::shared_ptr<Channel>) { //kris
}


std::string TuTubo::createUser(std::string, std::string, std::string) { //kris
}

std::shared_ptr<Channel> TuTubo::login(std::string, std::string) { //kris
}

std::string TuTubo::uploadVideo(std::string video, int type) { //Derek
    //agregar un video a la lista general y al canal
    std::stringstream s;

    if (activeSession == nullptr) {
        throw MissingAccount();
    }

    if (videosManagement == nullptr) {
        throw VideosNotAvailable();
    }

    std::shared_ptr<Video> newVideo;

    if (type == 1) {
        newVideo = std::make_shared<MP4>(video);
    }
    else if (type == 2) {
        std::shared_ptr<MPG> mpgVideo = std::make_shared<MPG>();
        newVideo = std::make_shared<AdapterMPG>(mpgVideo, video);
    }
    else {
        throw VideosNotAvailable();
    }

    videosManagement->addVideo(newVideo);

    s << activeSession->uploadVideo(newVideo);

    return s.str();
}

std::string TuTubo::suscribeToChannel(std::string channelName) { //Derek
    //mostrar lista de canales, preguntar y que seleccionen por numero
    std::stringstream s;

    if (activeSession == nullptr) {
        throw MissingAccount();
    }

    auto channelsList = channelsManagement->getChannelsList();
    s << "Canales disponibles:\n" << channelsList->showList();

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    s << "\n" << targetChannel->addSuscriber(activeSession);

    return s.str();
}

std::string TuTubo::unsuscribeFromChannel(std::string channelName) { //Derek
    //mostrar todos los canales suscritos, preguntar y seleccionar por nombre
    std::stringstream s;

    if (activeSession == nullptr) {
        throw MissingAccount();
    }

    auto subscriptionsList = activeSession->getSubscriptions();
    s << "Canales a los que estás suscrito:\n" << subscriptionsList->showList();

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    subscriptionsList->deleteElement(targetChannel);
    s << "\nTe desuscribiste de: " << targetChannel->getName();

    return s.str();
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

std::string TuTubo::searchVideoByChannel(std::string channelName, std::string videoName) { //Derek
    std::stringstream s;

    if (videosManagement == nullptr) {
        throw VideosNotAvailable();
    }

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    if (targetChannel == nullptr) {
        throw MissingChannel();
    }


    auto video = targetChannel->searchVideoName(videoName);

    if (video == nullptr) {
        throw MissingVideo();
    }

    s << "Video encontrado en canal " << targetChannel->getName() << ": " << video->getVideoName();

    return s.str();

}

std::string TuTubo::playVideo(std::shared_ptr<Video>) { //Derek
    //preguntar el video a ver y seleccionar
}
