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

std::string Channel::uploadVideo(std::shared_ptr<Video> newVideo)
{
    std::stringstream ss;
    if (newVideo != nullptr)
    {
        uploadedVideos->insertFirst(newVideo);

        ss << "* Video subido correctamente! *\n"
        << "Se ha Notificado a los suscriptores:\n"
        << notifySubscribers(getName(), newVideo->getVideoName());
    }
    return ss.str();
}

std::shared_ptr<List<Video>> Channel::getUploadedVideos() { return uploadedVideos; }

std::shared_ptr<Video> Channel::searchVideoName(std::string title)
{
    if (uploadedVideos->isEmpty()) throw MissingVideo();

    std::shared_ptr<ConcreteIterator<Video>> iterator = uploadedVideos->createIterator();
    std::shared_ptr<Video> video = nullptr;
    bool found = false;

    while (iterator->hasNext() && !found)
    {
        if (iterator->getNext()->getVideoName() == title)
        {
            found = true;
            video = iterator->getNext();
        }
    }

    if (video == nullptr) throw MissingVideo();
}

std::string Channel::notifySubscribers(std::string channelName, std::string videoTitle)
{
    if (suscribers->isEmpty()) throw NoSuscribers();

    std::stringstream ss;
    auto iterator = suscribers->createIterator();

    while (iterator->hasNext())
    {
        ss << "[" << std::dynamic_pointer_cast<Channel>(iterator->getNext())->getName() << "]: "
            << "Nuevo video subido en " << channelName << " - " << videoTitle << "\n";
    }

    return ss.str();
}