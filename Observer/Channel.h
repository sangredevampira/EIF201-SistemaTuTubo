//
// Created by XPC on 23/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_CHANNEL_H
#define PROYECTO_2___KRIS_Y_DEREK_CHANNEL_H

#include "ObserverInterface.h"
#include "../Iterator/List.h"
#include "../Exceptions/MissingVideo.h"
#include "../Exceptions/NoSuscribers.h"
#include "../Exceptions/VideosNotAvailable.h"

class Channel : public ObserverInterface
{
private:
    std::string name;
    std::shared_ptr<List<Video>> uploadedVideos;
    std::shared_ptr<List<Channel>> subscriptions;
    std::shared_ptr<List<ObserverInterface>> suscribers;
public:
    Channel(std::string name = "");
    std::string getName();
    std::string uploadVideo(std::shared_ptr<Video>);
    std::shared_ptr<List<Video>> getUploadedVideos();
    std::shared_ptr<Video> searchVideoName(std::string);

    std::string notifySubscribers(std::string, std::string) override;
};

#endif //PROYECTO_2___KRIS_Y_DEREK_CHANNEL_H