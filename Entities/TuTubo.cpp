//
// Created by derek on 25/05/2026.
//

#include "TuTubo.h"

TuTubo::TuTubo(){
    activeSession = nullptr;
    channelsManagement = std::make_shared<ChannelsController>();
    videosManagement = std::make_shared<VideosController>();
    usersManagement = std::make_shared<UsersController>();
}

void TuTubo::setActiveSession(std::shared_ptr<Channel> loggedChannel) { activeSession = loggedChannel; }

std::shared_ptr<UsersController> TuTubo::getUsersManagement() { return usersManagement; }


std::string TuTubo::createUser(std::string username, std::string password, std::string channelName) { //kris
    if (!usersManagement->existingUser(username))
        channelsManagement->addChannel(usersManagement->addUser(username, password, channelName));
    else throw DuplicatedUser();
    return "* Usuario registrado exitosamente!";
}

std::string TuTubo::login(std::string username, std::string password) {
    auto loggedChannel = usersManagement->login(username, password);
    setActiveSession(loggedChannel);
    return "[" + loggedChannel->getName() + "]: Has iniciado sesion con exito!";
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

std::string TuTubo::suscribeToChannel(std::string channelName) {
    //Derek
    //mostrar lista de canales, preguntar y que seleccionen por numero
    //Agrega a Derek como suscriptor de MusicChannel (para notificaciones)
    // MusicChannel a las suscripciones de Derek (para que lo vea)
    std::stringstream s;

    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }

    auto channelsList = channelsManagement->getChannelsList();
    s << "Canales disponibles:\n" << channelsList->showList();

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    s << "\n" << targetChannel->addSuscriber(activeSession); //cuando el canal suba un video, notificara a Derek

    s << "\n" << activeSession->addChannelSuscription(targetChannel); //Derek puede ver a que canales esta suscritos

    return s.str();
}

std::string TuTubo::unsuscribeFromChannel(std::string channelName) { //Derek
    //mostrar todos los canales suscritos, preguntar y seleccionar por nombre
    //Derek ya no ve a MusicChannel en su lista de suscripciones
    //MusicChannel ya no envía notificaciones a Derek
    //Derek no aparece más en los suscriptores de MusicChanne
    std::stringstream s;

    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }

    auto subscriptionsList = activeSession->getSubscriptions();
    s << "Canales a los que estás suscrito:\n" << subscriptionsList->showList();

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    subscriptionsList->deleteElement(targetChannel);

    s << "\n" << targetChannel->removeSuscriber(activeSession);

    if (targetChannel != nullptr)
    {
        subscriptionsList->deleteElement(targetChannel);
        s << "\nTe desuscribiste de: " << targetChannel->getName();
    }

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
