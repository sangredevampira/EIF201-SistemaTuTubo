//
// Created by derek on 21/05/2026.
//

#include "AdapterMPG.h"

AdapterMPG::AdapterMPG(std::shared_ptr<MPG> mpg, std::string name): Video(name) {
    this->mpg = mpg;
}

std::string AdapterMPG::play() {
    mpg->playAntiguo();
    return "Reproduciendo video: " + videoName;
}

std::string AdapterMPG::getVideoName() {
    return  mpg->playAntiguo() + videoName;
}
