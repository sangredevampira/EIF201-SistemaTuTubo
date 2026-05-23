//
// Created by XPC on 23/4/2026.
//

#ifndef PATRON_FACHADA_INCORRECTPASSWORD_H
#define PATRON_FACHADA_INCORRECTPASSWORD_H

#include "GeneralException.h"

class IncorrectPassword : public GeneralException
{
public:
    IncorrectPassword();
};


#endif //PATRON_FACHADA_INCORRECTPASSWORD_H