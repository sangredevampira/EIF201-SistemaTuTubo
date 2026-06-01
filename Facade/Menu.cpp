//
// Created by derek on 27/05/2026.
//

#include "Menu.h"

Menu::Menu() { tuTubo = std::make_unique<TuTubo>(); }

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
                    videoHandlingActions(); break;
                case 3:
                    saveDataManually(); break;
                case 4:
                    loadDataManually(); break;
                case 5:
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
            case 2: doLogin(); break;
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
    int index;

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

    std::cout << tuTubo->createUser(username, password, channelName) << "\n\n";

    std::cout << "--- Deseas iniciar sesion en este momento? ---\n"
                          << "(1) Si\n"
                          << "(0) No\n"
                          << "* Digita la opcion deseada: "; std::cin >> index;

    if (std::cin.fail()) throw Miscapture();

    switch (index)
    {
        case 1: doLogin(); break;
        case 0: return;
        default: throw IndexOutOfRange();
    }
}

void Menu::doLogin()
{
    ConsoleService::clearConsole();

    std::string username, password;

    std::cout << "------------------ * -------------------\n"
                         << "     INGRESA LOS DATOS DEL USUARIO\n"
                         << "------------------ * -------------------\n";
    std::cout << "* Digita el username: "; std::cin.ignore(); std::getline(std::cin, username);
    if (std::cin.fail() || username.empty()) throw Miscapture();

    std::cout << "* Digita la contrasena: "; std::cin.ignore(); std::getline(std::cin, password);
    if (std::cin.fail() || password.empty()) throw Miscapture();

    std::cout << tuTubo->login(username, password) << "\n\n";

    ConsoleService::pause();
}

void Menu::uploadVideoToMyChannel()
{
    ConsoleService::clearConsole();

    std::string videoTitle;

    std::cout << "------------------ * -------------------\n"
              << "     PUBLICAR UN VIDEO EN EL CANAL\n"
              << "          [FORMATOS ACEPTADOS] \n"
              << "              .MP4 Y .MPG"
              << "------------------ * -------------------\n";

    std::cout << "* Digita el titulo del video (debe indicar su formato): "; std::cin.ignore(); std::getline(std::cin, videoTitle);
    if (std::cin.fail() || videoTitle.empty()) throw Miscapture();

    std::cout << tuTubo->uploadVideo(videoTitle) << "\n\n";

    ConsoleService::pause();
}

void Menu::subscribeToChannel()
{
    ConsoleService::clearConsole();

    std::string channelName;

    std::cout << "------------------ * -------------------\n"
              << "       SUSCRIBIRSE A UN CANAL\n"
              << "------------------ * -------------------\n";

    std::cout << tuTubo->showAllChannels() << "\n";
    std::cout << "* Digita el nombre del canal: ";
    std::cin.ignore();
    std::getline(std::cin, channelName);

    if (!ConsoleService::validateID(channelName)) throw Miscapture();

    std::cout << tuTubo->suscribeToChannel(channelName) << "\n";

    ConsoleService::pause();
}

void Menu::unsubscribeToChannel()
{
    ConsoleService::clearConsole();

    std::string channelName;

    std::cout << "------------------ * -------------------\n"
              << "      DESUSCRIBIRSE DE UN CANAL\n"
              << "------------------ * -------------------\n";
    std::cout << tuTubo->showSubscriptionsList() << "\n";
    std::cout << "* Digita el nombre del canal: "; std::cin.ignore(); std::getline(std::cin, channelName);
    if (!ConsoleService::validateID(channelName)) throw Miscapture();
    //if (std::cin.fail() || channelName.empty()) throw Miscapture();

    std::cout << tuTubo->unsuscribeFromChannel(channelName) << "\n\n";

    ConsoleService::pause();
}

void Menu::videoHandling() {
    std::cout << "========================================\n"
                     << "          Menu Videos  \n"
                     << "========================================\n"
                     << "(1) Buscar Videos por Nombre\n"
                     << "(2) Buscar Videos por Canal de Usuario\n"
                    << "(3)  Reproducir Video\n"
                     << "(4) Salir\n"
                     << "* Digita la opcion deseada: ";
}

void Menu::videoHandlingActions() {
    int option = -1;
    bool back = false;

    do {
        try {
            videoHandling();
            std::cin >> option;
            if (std::cin.fail()) throw Miscapture();

            switch (option) {
                case 1:
                    searchVideoByName(); break;
                case 2:
                    searchVideoByChannel(); break;
                case 3:
                    playVideoMenu(); break;
                case 4:
                    back = true; break;
                default:
                    throw IndexOutOfRange();
            }
        } catch (std::exception& e) {
            ConsoleService::clearConsole();
            std::cout << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (!back);
}

void Menu::searchVideoByName() {
    try {
        ConsoleService::clearConsole();
        std::string videoName;

        std::cout << "----------------------------------------\n"
                  << "    BUSCAR VIDEO POR NOMBRE\n"
                  << "----------------------------------------\n"
                  << "* Digita el nombre del video: ";
        std::cin.ignore();
        std::getline(std::cin, videoName);

        if (!ConsoleService::validateVideoName(videoName)) throw Miscapture();

        std::cout << tuTubo->searchVideoByTitle(videoName) << "\n";

        ConsoleService::pause();
    } catch (std::exception& e) {
        ConsoleService::clearConsole();
        std::cout << e.what() << '\n';
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

void Menu::searchVideoByChannel() {
    try {
        ConsoleService::clearConsole();
        std::string channelName, videoName;

        std::cout << "----------------------------------------\n"
                  << "  BUSCAR VIDEOS POR CANAL DE USUARIO\n"
                  << "----------------------------------------\n"
                  << "* Digita el nombre del canal: ";
        std::cin.ignore();
        std::getline(std::cin, channelName);

        if (!ConsoleService::validateID(channelName)) throw Miscapture();

        if (!tuTubo->channelExists(channelName)) throw MissingChannel();

        std::cout << "* Digita el nombre del video en el canal: ";
        std::getline(std::cin, videoName);

        if (!ConsoleService::validateVideoName(videoName)) throw Miscapture();

        std::cout << tuTubo->searchVideoByChannel(channelName, videoName) << "\n";

        ConsoleService::pause();
    } catch (const std::exception& e) {
        ConsoleService::clearConsole();
        std::cout << "Error: " << e.what() << '\n';
        ConsoleService::pause();
    }
}

void Menu::playVideoMenu() {
    try {
        ConsoleService::clearConsole();
        std::string videoName;

        std::cout << "* Digita el nombre del video: ";
        std::cin.ignore();
        std::getline(std::cin, videoName);

        if (!ConsoleService::validateVideoName(videoName)) throw Miscapture();
        std::cout << tuTubo->playVideo(videoName) << "\n";

        ConsoleService::pause();
    } catch (const std::exception& e) {
        ConsoleService::clearConsole();
        std::cout << "Error: " << e.what() << '\n';
        ConsoleService::pause();
    }
}


void Menu::saveDataManually() {
}

void Menu::loadDataManually() {
}



