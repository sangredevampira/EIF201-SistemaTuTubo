//
// Created by XPC on 23/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_USERSCONTROLLER_H
#define PROYECTO_2___KRIS_Y_DEREK_USERSCONTROLLER_H

#include "../Entities/User.h"
#include "../Exceptions/NoRegisteredUsers.h"
#include "../Exceptions/MissingAccount.h"
#include "../Exceptions/IncorrectPassword.h"


class UsersController
{
private:
    std::shared_ptr<ListInterface<User>> usersList;
public:
    UsersController();
    std::shared_ptr<ListInterface<User>> getUsersList();
    std::shared_ptr<Channel> login(std::string, std::string);
    std::shared_ptr<Channel> addUser(std::string, std::string, std::string);
    bool existingUser(std::string);
};


#endif //PROYECTO_2___KRIS_Y_DEREK_USERSCONTROLLER_H