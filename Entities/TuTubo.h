//
// Created by derek on 25/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_TUTUBO_H
#define PROYECTO_2___KRIS_Y_DEREK_TUTUBO_H

#include "../Exceptions/MissingVideo.h"
#include "../Exceptions/VideosNotAvailable.h"
#include "../Exceptions/NoActiveAccount.h"
#include "../Exceptions/DuplicatedUser.h"
#include "../Controllers/ChannelsController.h"
#include "../Controllers/UsersController.h"
#include "../Controllers/VideosController.h"
#include "../Controllers/UsersController.h"
#include "../Adapter/MP4.h"
#include "../Adapter/MPG.h"
#include "../Adapter/AdapterMPG.h"
#include "../Exceptions/FormatNotAvaible.h"


class TuTubo {
private:
    std::shared_ptr<Channel> activeSession;
    std::shared_ptr<ChannelsController> channelsManagement;
    std::shared_ptr<VideosController> videosManagement;
    std::shared_ptr<UsersController> usersManagement;
public:
    TuTubo();

    void setActiveSession(std::shared_ptr<Channel>);
    std::shared_ptr<UsersController> getUsersManagement();
    std::string createUser(std::string,std::string,std::string);
    std::string login(std::string,std::string); // falta clase aunthenticator
    std::string uploadVideo(std::string); //falta ChannelsController
    std::string suscribeToChannel(std::string);
    std::string unsuscribeFromChannel(std::string);
    std::string searchVideoByTitle(std::string);
    std::string searchVideoByChannel(std::string,std::string); //falta ChannelsController
    std::string playVideo(std::shared_ptr<Video>);
    bool channelExists(std::string channelName);
};


#endif //PROYECTO_2___KRIS_Y_DEREK_TUTUBO_H