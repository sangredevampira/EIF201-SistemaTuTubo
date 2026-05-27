//
// Created by XPC on 23/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_OBSERVERINTERFACE_H
#define PROYECTO_2___KRIS_Y_DEREK_OBSERVERINTERFACE_H

#include "../Adapter/Video.h"
#include "../Utilities/Utilities.h"

class ObserverInterface {
public:
    virtual std::string notifySubscribers(std::string, std::string) = 0;
    friend std::ostream& operator<<(std::ostream& os, const ObserverInterface& observer);
};
std::ostream& operator<<(std::ostream& os, const ObserverInterface& observer);

#endif //PROYECTO_2___KRIS_Y_DEREK_OBSERVERINTERFACE_H