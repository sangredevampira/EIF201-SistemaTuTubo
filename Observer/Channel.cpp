//
// Created by XPC on 23/5/2026.
//

#include "Channel.h"

Channel::Channel(std::string name)
    : name(name)
{
    uploadedVideos = std::make_shared<List<Video>>();
    subscriptions = std::make_shared<List<Channel>>();
    suscribers = std::make_shared<List<ObserverInterface>>();
}

std::string Channel::getName() { return name; }

std::shared_ptr<ListInterface<Channel>> Channel::getSubscriptions() {
    return subscriptions;
}

std::shared_ptr<ListInterface<ObserverInterface>> Channel::getSubscribers() { return suscribers; }

std::string Channel::uploadVideo(std::shared_ptr<Video> newVideo)
{
    std::stringstream ss;
    if (newVideo != nullptr)
    {
        uploadedVideos->insertFirst(newVideo);
        ss << "* Video subido correctamente! *\n";

        try {
            ss << notifySubscribers(getName(), newVideo->getVideoName());
        } catch (const NoSuscribers& e) {
            ss << e.what();
        }
    }
    return ss.str();
}

std::shared_ptr<ListInterface<Video>> Channel::getUploadedVideos() { return uploadedVideos; }

std::shared_ptr<Video> Channel::searchVideoName(std::string title)
{
    if (uploadedVideos->isEmpty()) throw VideosNotAvailable();

    auto iterator = uploadedVideos->createIterator();
    std::shared_ptr<Video> video = nullptr;
    bool found = false;

    while (iterator->hasNext())
    {
        auto currentVideo = iterator->getNext();

        if (currentVideo->getVideoName() == title)
        {
            found = true;
            video = currentVideo;
        }
    }

    if (!found) throw MissingVideo();

    return video;
}

std::string Channel::notifySubscribers(std::string channelName, std::string videoTitle)
{
    if (suscribers->isEmpty()) {
        throw NoSuscribers();
    }

    std::stringstream ss;
    auto iterator = suscribers->createIterator();

    while (iterator->hasNext())
    {
        ss << "[" << std::dynamic_pointer_cast<Channel>(iterator->getNext())->getName() << "]: "
            << "Nuevo video subido en " << channelName << " - " << videoTitle << "\n";
    }

    return ss.str();
}

std::string Channel::addSuscriber(std::shared_ptr<ObserverInterface> suscriber) {
    std::stringstream s;
    if (suscriber != nullptr){
        suscribers->insertFirst(suscriber);
        s << "Suscripcion agregado al canal: " << getName();
    }
    return s.str();
}

std::string Channel::addChannelSuscription(std::shared_ptr<Channel> channel) {
    std::stringstream s;
    if (channel != nullptr){
        subscriptions->insertFirst(channel);
        s << "Canal suscrito correctamente!";
    }
    return s.str();
}

std::string Channel::removeSuscriber(std::shared_ptr<ObserverInterface> suscriber) {
    std::stringstream s;
    if (suscriber != nullptr){
        suscribers->deleteElement(suscriber);
        s << "Te desuscribiste del canal: " << getName();
    }
    return s.str();

}

bool Channel::isSubscribedTo(std::shared_ptr<Channel> channel) {
    if (subscriptions->isEmpty()) {
        return false;
    }

    auto iterator = subscriptions->createIterator();
    while (iterator->hasNext()) {
        if (iterator->getNext() == channel) {
            return true;
        }
    }
    return false;
}

bool Channel::hasSubscriber(std::shared_ptr<ObserverInterface> subscriber) {
    if (suscribers->isEmpty()) {
        return false;
    }

    auto iterator = suscribers->createIterator();
    while (iterator->hasNext()) {
        if (iterator->getNext() == subscriber) {
            return true;
        }
    }
    return false;
}

std::string Channel::showSubscriptionsList() {
    if (subscriptions->isEmpty()) {
        throw NoChannelSubscriptions();
    }

    std::stringstream s;
    s << "Canales a los que estas suscrito:\n" << subscriptions->showList();
    return s.str();
}


std::ostream & operator<<(std::ostream &os, const Channel &channel) {
    os << channel.name;
    return os;
}
