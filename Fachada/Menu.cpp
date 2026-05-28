//
// Created by derek on 27/05/2026.
//

#include "Menu.h"

Menu::Menu() {
    this->tuTubo = std::make_unique<TuTubo>();
}

void Menu::mainMenu() {

    std::cout << "=======================================\n"
            << "  * TuTubo *\n"
            << "       Plataforma " << "\n" //falta meter el tuTubo->getNombre()
            << "=======================================\n"
            << "(1) Manejo de Usuarios" << "\n"
            << "(2) Manejo de Videos" << "\n"
            << "(3) Guardar Datos Manualmente" << "\n"
            << "(4) Recuperar Datos Manualmente" << "\n"
            << "(5) Salir" << "\n"
            << "* Digita la opcion deseada: ";
}

void Menu::actionsMainMenu() {

    int option;
    bool continueMenu = true;

    do
    {
        try
        {
            mainMenu();
            std::cin>>option;
            if (std::cin.fail()) throw Miscapture();

            switch (option)
            {
                case 1:
                    userManagement(); break;
                case 2:
                    videoHandling(); break;
                case 3:
                    saveDataManually(); break;
                case 4:
                    loadDataManually(); break;
                case 0:
                    ConsoleService::clearConsole();
                    finalMessage();
                    continueMenu = false; break;
                default:
                    throw IndexOutOfRange();
            }
        }catch (std::exception& e)
        {
            ConsoleService::clearConsole();
            std::cout << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

    }while (continueMenu);
}

void Menu::finalMessage() {

    std::cout << "\t--------------------------------------------------------------------------------\n"
               << "\t * GRACIAS POR USAR EL SISTEMA TuTubo " << " * \n" //falta meter el tuTubo->getNombre()
               << "\t\t\t\t\t Hasta pronto! :)\n";
}

void Menu::userManagement() {
}

void Menu::videoHandling() {
}

void Menu::saveDataManually() {
}

void Menu::loadDataManually() {
}
