//
// Created by XPC on 17/4/2026.
//

#include "GeneralException.h"

GeneralException::GeneralException(std::string message)
    : message(message)
{}

const char* GeneralException::what() const noexcept
{
    return message.c_str();
}

