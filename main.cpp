//
// Created by derek on 21/05/2026.
//

#include "Facade/Menu.h"

int main() {
    try
    {
        std::unique_ptr<Menu> menu = std::make_unique<Menu>();
        menu->actionsMainMenu();
    }catch (...)
    {
        std::cout << "Se debe reiniciar el programa\n";
    }


}