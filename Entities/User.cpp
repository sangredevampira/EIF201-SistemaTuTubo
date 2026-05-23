//
// Created by XPC on 23/5/2026.
//

#include "User.h"

User::User(std::string username, std::string password, std::string channelName)
    : username(username), password(password)
{ ownedChannel = std::make_shared<Channel>(channelName); }

std::string User::getUsername() const { return username; }

std::string User::getPassword() const { return password;}

std::shared_ptr<Channel> User::getOwnedChannel() const { return ownedChannel; }

bool User::verifyPassword(std::string otherPassword) const { return getPassword() == otherPassword; }
