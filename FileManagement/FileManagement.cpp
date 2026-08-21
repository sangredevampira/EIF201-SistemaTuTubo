//
// Created by XPC on 30/5/2026.
//

// holis estoy haciendo una prueba

#include "FileManagement.h"

FileManagement *FileManagement::instance = nullptr;

FileManagement* FileManagement::getInstance()
{
    if (!instance)
        instance = new FileManagement();
    return instance;
}

void FileManagement::clearUsersList(std::shared_ptr<ListInterface<User>> &usersList)
{
    if (!usersList) return;
    while (!usersList->isEmpty()) usersList->deleteElement(usersList->getFirst()->getElement());
}

void FileManagement::clearChannelsList(std::shared_ptr<ListInterface<Channel>> &channelsList)
{
    if (!channelsList) return;
    while (!channelsList->isEmpty()) channelsList->deleteElement(channelsList->getFirst()->getElement());
}

void FileManagement::clearVideosList(std::shared_ptr<ListInterface<Video>> &videosList)
{
    if (!videosList) return;
    while (!videosList->isEmpty()) videosList->deleteElement(videosList->getFirst()->getElement());
}

//------------------------------------------------------------------------------------------------------------------------------


std::string FileManagement::saveData(std::shared_ptr<ListInterface<User>> usersList)
{
    Json::StreamWriterBuilder builder;
    builder["CommentStyle"] = "None";
    builder["Indentation"] = "   ";
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    std::ofstream file("SistemaTutubo.txt");
    if (!file.is_open()) throw MissingFile();

    Json::Value event;

    event["Users"] = saveUserData(usersList);
    writer->write(event, &file);
    file.close();

    return "Datos guardados correctamente!";
}

Json::Value FileManagement::saveUserData(std::shared_ptr<ListInterface<User>> usersList)
{
    Json::Value arreglo(Json::arrayValue);
    auto iterador = usersList->createIterator();

    while (iterador->hasNext())
    {
        Json::Value user;
        auto currentUser = iterador->getNext();
        user["Username"] = currentUser->getUsername();
        user["Password"] = currentUser->getPassword();
        user["Channel"] = saveChannelData(currentUser->getOwnedChannel());
        arreglo.append(user);
    }
    return arreglo;
}

Json::Value FileManagement::saveChannelData(std::shared_ptr<Channel> channel)
{
    Json::Value channelEvent;
    channelEvent["Channel_Name"] = channel->getName();
    channelEvent["Uploaded_Videos"] = saveVideosData(channel->getUploadedVideos());
    channelEvent["Subscriptions"] = saveSubscriptionsData(channel->getSubscriptions());
    channelEvent["Subscribers"] = saveSubscribersData(channel->getSubscribers());

    return channelEvent;
}

Json::Value FileManagement::saveVideosData(std::shared_ptr<ListInterface<Video>> videosList)
{
    Json::Value arreglo(Json::arrayValue);
    auto iterador = videosList->createIterator();

    while (iterador->hasNext())
    {
       Json::Value videosEvent;
        videosEvent["Title"] = iterador->getNext()->getVideoName();
        arreglo.append(videosEvent);
    }
    return arreglo;
}

Json::Value FileManagement::saveSubscriptionsData(std::shared_ptr<ListInterface<Channel>> subscriptions)
{
    Json::Value arreglo(Json::arrayValue);
    auto iterador = subscriptions->createIterator();

    while (iterador->hasNext())
    {
        Json::Value subscriptionEvent;
        subscriptionEvent["Channel_Name"] = iterador->getNext()->getName();
        arreglo.append(subscriptionEvent);
    }
    return arreglo;
}

Json::Value FileManagement::saveSubscribersData(std::shared_ptr<ListInterface<ObserverInterface>> subscribers)
{
    Json::Value arreglo(Json::arrayValue);
    auto iterador = subscribers->createIterator();

    while (iterador->hasNext())
    {
        Json::Value subscriptionEvent;
        subscriptionEvent["Channel_Name"] = iterador->getNext()->getName();
        arreglo.append(subscriptionEvent);
    }
    return arreglo;
}

//------------------------------------------------------------------------------------------------------------------------------

//  metodos para leer archivos

std::string FileManagement::loadData( std::shared_ptr<ListInterface<User>> usersList,
    std::shared_ptr<ListInterface<Channel>> channelsList, std::shared_ptr<ChannelsController> channelsManagement, std::shared_ptr<ListInterface<Video>> videosList)
{
    std::ifstream file("SistemaTutubo.txt");
    if (!file.is_open()) throw MissingFile();

    clearUsersList(usersList);
    clearChannelsList(channelsList);
    clearVideosList(videosList);

    Json::Value object;
    Json::Reader reader;

    if (!reader.parse(file, object)) throw LoadDataError();

    loadUsersData(object["Users"], usersList, channelsList, videosList);

    for (Json::ArrayIndex i = 0; i < object["Users"].size(); i++) {
        std::string channelName = object["Users"][i]["Channel"]["Channel_Name"].asString();
        auto channel = channelsManagement->searchChannel(channelName);

        if (channel) {
            loadSubscriptionsData(object["Users"][i]["Channel"]["Subscriptions"], channel, channelsManagement);
            loadSubscribersData(object["Users"][i]["Channel"]["Subscribers"], channel, channelsManagement);
        }
    }


    return "Datos cargados correctamente!";
}

void FileManagement::loadUsersData(const Json::Value& object, std::shared_ptr<ListInterface<User>> &usersList,
    std::shared_ptr<ListInterface<Channel>> &channelsList, std::shared_ptr<ListInterface<Video>> &videosList)
{
    for (Json::ArrayIndex i = 0; i < object.size(); i++)
    {
        std::string username = object[i]["Username"].asString();
        std::string password = object[i]["Password"].asString();

        auto user = std::make_shared<User>(username, password);

        loadChannelsData(object[i]["Channel"], channelsList, videosList, user);

        usersList->insertLast(user);
    }
}

void FileManagement::loadChannelsData(const Json::Value& object, std::shared_ptr<ListInterface<Channel>> &channelsList,
    std::shared_ptr<ListInterface<Video>> &videosList, std::shared_ptr<User> user)
{
    std::string channelName = object["Channel_Name"].asString();

    auto channel = std::make_shared<Channel>(channelName);
    user->setOwnedChannel(channel);
    channelsList->insertLast(channel);

    loadVideosData(object["Uploaded_Videos"], videosList, channel);
}

void FileManagement::loadVideosData(const Json::Value& object, std::shared_ptr<ListInterface<Video>> &videosList,
    std::shared_ptr<Channel> channel)
{
    std::shared_ptr<Video> newVideo = nullptr;

    for (Json::ArrayIndex i = 0; i < object.size(); i++)
    {
        std::string title = object[i]["Title"].asString();

        size_t pos = title.rfind('.');
        std::string extension = title.substr(pos);
        std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

        if (extension == ".mp4") {
            newVideo = std::make_shared<MP4>(title);
        }
        else if (extension == ".mpg") {
            std::shared_ptr<MPG> mpgVideo = std::make_shared<MPG>();
            newVideo = std::make_shared<AdapterMPG>(mpgVideo, title);
        }

        channel->getUploadedVideos()->insertLast(newVideo);
        videosList->insertLast(newVideo);
    }
}

void FileManagement::loadSubscriptionsData(const Json::Value& object, std::shared_ptr<Channel> &channel, std::shared_ptr<ChannelsController> &channelManagement)
{
    for (Json::ArrayIndex i = 0; i < object.size(); i++) {
        auto subscription = channelManagement->searchChannel(object[i]["Channel_Name"].asString());
        if (subscription) {
            channel->addChannelSuscription(subscription);
        }
    }


}

void FileManagement::loadSubscribersData(const Json::Value& object, std::shared_ptr<Channel> channel, std::shared_ptr<ChannelsController> &channelManagement)
{

    for (Json::ArrayIndex i = 0; i < object.size(); i++) {
        auto subscriber = channelManagement->searchChannel(object[i]["Channel_Name"].asString());
        if (subscriber) {
            channel->addSuscriber(subscriber);
        }
    }
}