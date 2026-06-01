//
// Created by XPC on 23/5/2026.
//

#include "User.h"

User::User(std::string username, std::string password, std::string channelName)
    : username(username), password(password)
{ ownedChannel = std::make_shared<Channel>(channelName); }

User::User(std::string username, std::string password)
    : username(username), password(password)
{ ownedChannel =  nullptr; }

std::string User::getUsername() const { return username; }

std::string User::getPassword() const { return password;}

std::shared_ptr<Channel> User::getOwnedChannel() const { return ownedChannel; }

void User::setOwnedChannel(std::shared_ptr<Channel> channel) { ownedChannel = channel; }

bool User::verifyUsername(std::string otherUsername) const { return getUsername() == otherUsername; }

bool User::verifyPassword(std::string otherPassword) const { return getPassword() == otherPassword; }

std::ostream & operator<<(std::ostream & os, const User &user) {
    os << user.username << "," << user.password;
    return os;
}
