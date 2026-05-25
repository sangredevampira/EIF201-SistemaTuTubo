//
// Created by derek on 25/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_TUTUBO_H
#define PROYECTO_2___KRIS_Y_DEREK_TUTUBO_H

#include "Exceptions/MissingVideo.h"
#include "Exceptions/VideosNotAvailable.h"
#include "Observer/Channel.h"
#include "VideosController.h"

class TuTubo {
private:
    std::shared_ptr<VideosController> videosManagement;
    std::shared_ptr<Channel> activeSession;
    //falta incluir la clase ChannelsController
    // falta incluir la clase Aunteticator
public:
    TuTubo();
    void setActiveSession(std::shared_ptr<Channel>);
    std::string createUser(std::string,std::string,std::string); // falta incluir la clase aunthenticator
    std::shared_ptr<Channel> login(std::string,std::string); // falta clase aunthenticator
    std::string uploadVideo(std::string); //falta ChannelsController
    std::string suscribeToChannel(std::string);
    std::string unsuscribeFromChannel(std::string);
    std::string searchVideoByTitle(std::string);
    std::string searchVideoByChannel(std::string,std::string); //falta ChannelsController
    std::string playVideo(std::shared_ptr<Video>);
};


#endif //PROYECTO_2___KRIS_Y_DEREK_TUTUBO_H