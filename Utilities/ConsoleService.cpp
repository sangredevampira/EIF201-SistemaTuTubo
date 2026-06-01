//
// Created by XPC on 31/3/2026.
//

#include "ConsoleService.h"

void ConsoleService::pause()
{
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void ConsoleService::clearConsole() { std::cout << std::string(10, '\n');}

bool ConsoleService::validateInput(const std::string& input)
{
    std::regex patron("^[A-Za-z ]+$");

    if (!std::regex_match(input, patron)) {
        return false;
    }
    for (char c : input) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            return true;
        }
    }

    return false;
}

bool ConsoleService::validateID(const std::string& id)
{
    std::regex patron("^[A-Za-z0-9]+$");
    return std::regex_match(id, patron);
}

bool ConsoleService::validateVideoName(const std::string& videoName)
{
    std::regex patron("^[A-Za-z0-9. ]+$");
    return std::regex_match(videoName, patron);
}
