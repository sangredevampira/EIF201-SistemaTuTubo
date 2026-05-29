//
// Created by derek on 27/05/2026.
//
#include "ObserverInterface.h"

std::ostream& operator<<(std::ostream& os, const ObserverInterface& observer) {
    os << "Observer";
    return os;
}