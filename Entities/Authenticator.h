//
// Created by XPC on 23/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_AUTHENTICATOR_H
#define PROYECTO_2___KRIS_Y_DEREK_AUTHENTICATOR_H

#include "UsersController.h"

class Authenticator
{
public:
    Authenticator() = default;
    std::shared_ptr<Channel> login(std::shared_ptr<UsersController>, std::string, std::string);
    std::string createUser(std::shared_ptr<UsersController>, std::string, std::string, std::string);
};


#endif //PROYECTO_2___KRIS_Y_DEREK_AUTHENTICATOR_H