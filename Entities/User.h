//
// Created by XPC on 23/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_USER_H
#define PROYECTO_2___KRIS_Y_DEREK_USER_H

#include "../Observer/Channel.h"

class User
{
private:
    std::string username;
    std::string password;
    std::shared_ptr<Channel> ownedChannel;
public:
    User(std::string, std::string, std::string);
    std::string getUsername() const;
    std::string getPassword() const;
    std::shared_ptr<Channel> getOwnedChannel() const;
    bool verifyPassword(std::string) const;
};


#endif //PROYECTO_2___KRIS_Y_DEREK_USER_H