//
// Created by XPC on 23/5/2026.
//


#include "UsersController.h"

UsersController::UsersController() { usersList = std::make_shared<List<User>>(); }


std::shared_ptr<ListInterface<User>> UsersController::getUsersList() { return usersList; }

std::shared_ptr<Channel> UsersController::login(std::string username, std::string password)
{
    if (usersList->isEmpty()) throw MissingAccount();

    auto iterator = usersList->createIterator();
    std::shared_ptr<Channel> channel = nullptr;
    bool found = false;

    while (iterator->hasNext())
    {
        auto user = iterator->getNext();

        if (user->verifyUsername(username))
        {
            found = true;

            if (user->verifyPassword(password))
                channel = user->getOwnedChannel();
            else throw IncorrectPassword();
        }
    }

    if (!found) throw MissingAccount();

    return channel;
}

std::shared_ptr<Channel> UsersController::addUser(std::string username, std::string password, std::string channelName)
{
    auto newUser = std::make_shared<User>(username, password, channelName);
    usersList->insertFirst(newUser);
    return newUser->getOwnedChannel();
}

bool UsersController::existingUser(std::string username)
{
    bool found = false;

    auto iterator = usersList->createIterator();

    while (iterator->hasNext())
    {
        auto user = iterator->getNext();

        if (user->verifyUsername(username)) found = true;
    }

    return found;
}
