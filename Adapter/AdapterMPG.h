//
// Created by derek on 21/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_ADAPTERMPG_H
#define PROYECTO_2___KRIS_Y_DEREK_ADAPTERMPG_H

#include "Video.h"
#include "MPG.h"
class AdapterMPG:public Video{
private:
    std::shared_ptr<MPG> mpg;
    public:
    AdapterMPG(std::shared_ptr<MPG> mpg, std::string name = "");
    std::string play() override;
    std::string getVideoName() override;
};


#endif //PROYECTO_2___KRIS_Y_DEREK_ADAPTERMPG_H