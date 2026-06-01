//
// Created by derek on 25/05/2026.
//

#include "TuTubo.h"

TuTubo::TuTubo(){
    activeSession = nullptr;
    channelsManagement = std::make_shared<ChannelsController>();
    videosManagement = std::make_shared<VideosController>();
    usersManagement = std::make_shared<UsersController>();
    FileManagement::getInstance()->loadData(getUsersList(),getChannelsManagement()->getChannelsList(), getChannelsManagement(), getVideosManagement()->getVideoList());
}

void TuTubo::setActiveSession(std::shared_ptr<Channel> loggedChannel) { activeSession = loggedChannel; }

TuTubo::~TuTubo() {
    FileManagement::getInstance()->saveData(getUsersList());
}

std::shared_ptr<ListInterface<User>> TuTubo::getUsersList() { return usersManagement->getUsersList(); }

std::shared_ptr<Channel> TuTubo::getActiveSession() { return activeSession; }

std::shared_ptr<UsersController> TuTubo::getUsersManagement() { return usersManagement; }

std::shared_ptr<ChannelsController> TuTubo::getChannelsManagement() {return channelsManagement; }

std::shared_ptr<VideosController> TuTubo::getVideosManagement() { return videosManagement; }

std::string TuTubo::createUser(std::string username, std::string password, std::string channelName) {
    if (usersManagement->existingUser(username)) throw DuplicatedUser();
    if (channelsManagement->existingChannel(channelName)) throw DuplicatedChannel();
    channelsManagement->addChannel(usersManagement->addUser(username, password, channelName));
    return "* Usuario registrado exitosamente!";
}

std::string TuTubo::login(std::string username, std::string password) {
    auto loggedChannel = usersManagement->login(username, password);
    setActiveSession(loggedChannel);
    return "[" + loggedChannel->getName() + "]: Has iniciado sesion exitosamente!";
}

std::string TuTubo::uploadVideo(std::string video) {
    std::stringstream s;

    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }

    if (videosManagement == nullptr) {
        throw VideosNotAvailable();
    }

    std::shared_ptr<Video> newVideo;

    size_t pos = video.rfind('.');
    if (pos == std::string::npos) {
        throw MissingVideo();
    }


    std::string extension = video.substr(pos);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

    if (extension == ".mp4") {
        newVideo = std::make_shared<MP4>(video);
    }
    else if (extension == ".mpg") {
        std::shared_ptr<MPG> mpgVideo = std::make_shared<MPG>();
        newVideo = std::make_shared<AdapterMPG>(mpgVideo, video);
    }
    else {
        throw FormatNotAvaible();
    }

    videosManagement->addVideo(newVideo);

    s << activeSession->uploadVideo(newVideo);

    return s.str();
}

std::string TuTubo::suscribeToChannel(std::string channelName) {
    std::stringstream s;

    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    if (activeSession == targetChannel) {
        throw CannotSubscribeToOwnChannel();
    }

    if (activeSession->isSubscribedTo(targetChannel)) {
        throw AlreadySubscribed();
    }

    s << "\n" << targetChannel->addSuscriber(activeSession);
    s << "\n" << activeSession->addChannelSuscription(targetChannel);

    return s.str();
}

std::string TuTubo::unsuscribeFromChannel(std::string channelName) {
    std::stringstream s;

    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }

    std::shared_ptr<Channel> targetChannel = channelsManagement->searchChannel(channelName);

    if (!activeSession->isSubscribedTo(targetChannel)) {
        throw NotSubscribed();
    }

    auto subscriptionsList = activeSession->getSubscriptions();
    subscriptionsList->deleteElement(targetChannel);
    s << targetChannel->removeSuscriber(activeSession);

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

    auto video = targetChannel->searchVideoName(videoName);

    if (video == nullptr) {
        throw MissingVideo();
    }

    s << "Video encontrado en canal " << targetChannel->getName() << ": " << video->getVideoName();

    return s.str();

}

std::string TuTubo::playVideo(std::string videoName) {
    std::stringstream s;

    if (videosManagement == nullptr) {
        throw VideosNotAvailable();
    }

    auto video = videosManagement->searchVideoName(videoName);

    if (video == nullptr) {
        throw MissingVideo();
    }

    s << video->play();

    return s.str();
}

std::string TuTubo::showSubscriptionsList() {
    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }
    return activeSession->showSubscriptionsList();
}

std::string TuTubo::showAllChannels() {
    std::stringstream s;

    if (activeSession == nullptr) {
        throw NoActiveAccount();
    }

    if (channelsManagement == nullptr) {
        throw MissingChannel();
    }

    s << "Canales disponibles:\n" << channelsManagement->showChannelsList();

    return s.str();
}

bool TuTubo::channelExists(std::string channelName) {
    return channelsManagement->existingChannel(channelName);
}
