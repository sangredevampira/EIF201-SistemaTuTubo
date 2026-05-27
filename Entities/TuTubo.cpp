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

std::string TuTubo::uploadVideo(std::string) { //Derek
    //agregar un video a la lista general y al canal
}

std::string TuTubo::suscribeToChannel(std::string) { //Derek
    //mostrar lista de canales, preguntar y que seleccionen por numero
}

std::string TuTubo::unsuscribeFromChannel(std::string) { //Derek
    //mostrar todos los canales suscritos, preguntar y seleccionar por numero
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

std::string TuTubo::searchVideoByChannel(std::string, std::string) { //Derek

}

std::string TuTubo::playVideo(std::shared_ptr<Video>) { //Derek
    //preguntar el video a ver y seleccionar
}
