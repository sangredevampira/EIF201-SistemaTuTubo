//
// Created by XPC on 17/4/2026.
//

#ifndef MANEJO_DE_EXCEPCIONES_GENERALEXCEPTION_H
#define MANEJO_DE_EXCEPCIONES_GENERALEXCEPTION_H

#include <exception>
#include <string>

class GeneralException : public std::exception
{
protected:
    std::string message;
public:
    GeneralException(std::string message);
    const char* what() const noexcept override;
};


#endif //MANEJO_DE_EXCEPCIONES_GENERALEXCEPTION_H