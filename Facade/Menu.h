//
// Created by derek on 27/05/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_MENU_H
#define PROYECTO_2___KRIS_Y_DEREK_MENU_H

#include "../Entities/TuTubo.h"
#include "../Exceptions/Miscapture.h"
#include "../Utilities/ConsoleService.h"
#include "../Exceptions/IndexOutOfRange.h"
class Menu {
private:
    std::unique_ptr<TuTubo> tuTubo;
public:
    Menu();

    void mainMenu();
    void actionsMainMenu();
    void finalMessage();

    void userManagement();
    void userManagementActions();
    void createUser();
    void doLogin();
    void uploadVideoToMyChannel();
    void subscribeToChannel();
    void unsubscribeToChannel();

    void videoHandling();
    void videoHandlingActions();
    void searchVideoByName();
    void searchVideoByChannel();
    void playVideoMenu();



    void saveDataManually();
    void loadDataManually();


};


#endif //PROYECTO_2___KRIS_Y_DEREK_MENU_H