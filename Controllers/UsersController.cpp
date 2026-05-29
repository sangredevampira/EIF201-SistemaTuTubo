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

std::string UsersController::addUser(std::string username, std::string password, std::string channelName)
{
    usersList->insertFirst(std::make_shared<User>(username, password, channelName));
    return "Usuario agregado exitosamente!";
}
