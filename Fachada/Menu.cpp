//
// Created by derek on 27/05/2026.
//

#include "Menu.h"

Menu::Menu() {
    this->tuTubo = std::make_unique<TuTubo>();
}

void Menu::mainMenu() {

    std::cout << "=======================================\n"
            << "        * Plataforma TuTubo * \n"
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
                    userManagementActions(); break;
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
               << "\t                 * GRACIAS POR USAR EL SISTEMA TUTUBO " << " * \n"
               << "\t\t\t\t\t Hasta pronto! :)\n";
}

void Menu::userManagement() {
    std::cout << "========================================\n"
                  << "         * SUBMENU DE USUARIOS *        \n"
                  << "========================================\n"
                  << "(1) Crear Usuario\n"
                  << "(2) Hacer Login\n"
                  << "(3) Subir Video a mi Canal\n"
                  << "(4) Suscribirme a un Canal\n"
                  << "(5) Desuscribirme de un Canal\n"
                  << "(0) Volver\n"
                  << "* Digita la opcion deseada: ";

}

void Menu::userManagementActions()
{
    int option = -1;
    bool back = false;

    do
    {
        ConsoleService::clearConsole();
        userManagement(); std::cin >> option;

        if (option < 0 || option > 5) throw IndexOutOfRange();
        if (std::cin.fail()) throw Miscapture();

        switch (option)
        {
            case 1: createUser(); break;
            case 2: doLoging(); break;
            case 3: uploadVideoToMyChannel(); break;
            case 4: subscribeToChannel(); break;
            case 5: unsubscribeToChannel(); break;
            case 0: back = true; break;
            default: throw IndexOutOfRange();
        }
    }while (!back);
}

void Menu::createUser()
{
    ConsoleService::clearConsole();

    std::string username, password, channelName;

    std::cout << "------------------ * -------------------\n"
                          << "     INGRESA LOS DATOS DEL USUARIO\n"
                          << "------------------ * -------------------\n";
    std::cout << "* Digita el username: "; std::cin.ignore(); std::getline(std::cin, username);
    if (std::cin.fail() || username.empty()) throw Miscapture();

    std::cout << "* Digita la contrasena: "; std::cin.ignore(); std::getline(std::cin, password);
    if (std::cin.fail() || password.empty()) throw Miscapture();

    std::cout << "* Digita el nombre del canal: "; std::cin >> channelName;
    if (std::cin.fail() ||
        channelName.empty()) throw Miscapture();

    std::cout << tuTubo->createUser(username, password, channelName);
}

void Menu::doLoging()
{
}

void Menu::uploadVideoToMyChannel()
{
}

void Menu::subscribeToChannel()
{
}

void Menu::unsubscribeToChannel()
{
}

void Menu::videoHandling() {
}

void Menu::saveDataManually() {
}

void Menu::loadDataManually() {
}
