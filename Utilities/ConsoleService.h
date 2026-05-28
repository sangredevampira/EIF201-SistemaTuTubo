//
// Created by XPC on 31/3/2026.
//

#ifndef PROYECTO_1_CONSOLESERVICE_H
#define PROYECTO_1_CONSOLESERVICE_H

#include "Utilities.h"
#include <regex>
#include <stdexcept>
#include <limits>

class ConsoleService
{
public:
    static void pause();
    static void clearConsole();

    static bool validateInput(const std::string&);
    static bool validateID(const std::string&);
};


#endif //PROYECTO_1_CONSOLESERVICE_H