//
// Created by XPC on 23/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_CHANNEL_H
#define PROYECTO_2___KRIS_Y_DEREK_CHANNEL_H

#include "ObserverInterface.h"
#include "../Iterator/List.h"
#include "../Adapter/Video.h"
#include "../Exceptions/MissingVideo.h"
#include "../Exceptions/NoSuscribers.h"
#include "../Exceptions/VideosNotAvailable.h"

class Channel : public ObserverInterface
{
private:
    std::string name;
    std::shared_ptr<ListInterface<Video>> uploadedVideos;
    std::shared_ptr<ListInterface<Channel>> subscriptions;
    std::shared_ptr<ListInterface<ObserverInterface>> suscribers;
public:
    Channel(std::string name = "");
    std::string getName() override;
    std::shared_ptr<ListInterface<Channel>> getSubscriptions();
    std::shared_ptr<ListInterface<ObserverInterface>> getSubscribers();
    std::string uploadVideo(std::shared_ptr<Video>);
    std::shared_ptr<ListInterface<Video>> getUploadedVideos();
    std::shared_ptr<Video> searchVideoName(std::string);
    std::string addSuscriber(std::shared_ptr<ObserverInterface> suscriber);
    std::string addChannelSuscription(std::shared_ptr<Channel> channel); //agrega a la lista de subs
    std::string removeSuscriber(std::shared_ptr<ObserverInterface> suscriber);

    std::string notifySubscribers(std::string, std::string) override;

    friend std::ostream& operator<<(std::ostream& os, const Channel &channel);
};

#endif //PROYECTO_2___KRIS_Y_DEREK_CHANNEL_H