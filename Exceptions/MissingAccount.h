//
// Created by XPC on 23/4/2026.
//

#ifndef PATRON_FACHADA_MISSINGACCOUNT_H
#define PATRON_FACHADA_MISSINGACCOUNT_H

#include "GeneralException.h"

class MissingAccount : public GeneralException
{
public:
    MissingAccount();
};


#endif //PATRON_FACHADA_MISSINGACCOUNT_H