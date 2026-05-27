//
// Created by XPC on 23/5/2026.
//

#include "Authenticator.h"

std::shared_ptr<Channel> Authenticator::login(std::shared_ptr<UsersController> controller, std::string username, std::string password)
{ return controller->login(username, password); }

std::string Authenticator::createUser(std::shared_ptr<UsersController> controller, std::string username, std::string password, std::string channelName)
{ return controller->addUser(username, password, channelName); }
