//
// Created by XPC on 30/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_FILEMANAGEMENT_H
#define PROYECTO_2___KRIS_Y_DEREK_FILEMANAGEMENT_H

#include "../dist/json/json.h"
#include "../Utilities/Utilities.h"
#include "../Controllers/UsersController.h"
#include "../Controllers/ChannelsController.h"

#include "../Exceptions/SaveDataError.h"
#include "../Exceptions/LoadDataError.h"
#include "../Exceptions/MissingFile.h"

class FileManagement
{
private:
    static FileManagement *instance;
    FileManagement() = default;
public:
    static FileManagement* getInstance();

    void clearUsersList(std::shared_ptr<ListInterface<User>> &);
    void clearChannelsList(std::shared_ptr<ListInterface<Channel>> &);
    void clearVideosList(std::shared_ptr<ListInterface<Video>> &);


    std::string saveData(std::shared_ptr<ListInterface<User>>);
    Json::Value saveUserData(std::shared_ptr<ListInterface<User>>);
    Json::Value saveChannelData(std::shared_ptr<Channel>);
    Json::Value saveVideosData(std::shared_ptr<ListInterface<Video>>);
    Json::Value saveSubscriptionsData(std::shared_ptr<ListInterface<Channel>>);
    Json::Value saveSubscribersData(std::shared_ptr<ListInterface<ObserverInterface>>);


    std::string loadData(std::shared_ptr<ListInterface<User>> &, std::shared_ptr<ListInterface<Channel>> &, std::shared_ptr<ListInterface<Video>> &);
    std::string loadUsersData(const Json::Value& object, std::shared_ptr<ListInterface<User>> &, std::shared_ptr<ListInterface<Channel>> &, std::shared_ptr<ListInterface<Video>> &);
    std::string loadChannelsData(const Json::Value& object, std::shared_ptr<ListInterface<Channel>> &, std::shared_ptr<ListInterface<Video>> &, std::shared_ptr<User>);
    std::string loadVideosData(const Json::Value& object, std::shared_ptr<ListInterface<Video>> &, std::shared_ptr<Channel>);
    std::string loadSubscriptionsData(const Json::Value& object, std::shared_ptr<Channel>);
    std::string loadSubscribersData(const Json::Value& object, std::shared_ptr<Channel>);

    FileManagement(FileManagement &other) = delete;
    void operator=(const FileManagement &) = delete;
};


#endif //PROYECTO_2___KRIS_Y_DEREK_FILEMANAGEMENT_H