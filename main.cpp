//
// Created by derek on 21/05/2026.
//
#include "Adapter/Video.h"
#include "Adapter/MP4.h"
#include "Adapter/AdapterMPG.h"
#include "Adapter/MPG.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "===== PRUEBA DEL PATRON ADAPTER =====" << std::endl << std::endl;

    // Crear un video MP4 (implementación directa)
    std::cout << "1. Videos MP4 (Interfaz Moderna):" << std::endl;
    std::shared_ptr<Video> video1 = std::make_shared<MP4>("Película.mp4");
    std::cout << "   " << video1->play() << std::endl;
    std::cout << "   Nombre: " << video1->getVideoName() << std::endl << std::endl;

    // Crear un video MPG antiguo y adaptarlo
    std::cout << "2. Video MPG (Interfaz Antigua) adaptado con Adapter:" << std::endl;
    std::shared_ptr<MPG> videoMPGAntiguo = std::make_shared<MPG>();
    std::shared_ptr<Video> video2 = std::make_shared<AdapterMPG>(videoMPGAntiguo, "Video.mpg");

    std::cout << "   " << video2->play() << std::endl;
    std::cout << "   Nombre: " << video2->getVideoName() << std::endl << std::endl;

    // Otro video MP4
    std::cout << "3. Otro video MP4:" << std::endl;
    std::shared_ptr<Video> video3 = std::make_shared<MP4>("Canción.mp4");
    std::cout << "   " << video3->play() << std::endl;
    std::cout << "   Nombre: " << video3->getVideoName() << std::endl << std::endl;

    // Otro video adaptado
    std::cout << "4. Otro video MPG adaptado:" << std::endl;
    std::shared_ptr<Video> video4 = std::make_shared<AdapterMPG>(std::make_shared<MPG>(), "Video antiguo.mpg");
    std::cout << "   " << video4->play() << std::endl;
    std::cout << "   Nombre: " << video4->getVideoName() << std::endl << std::endl;

    std::cout << "===== FIN DE LAS PRUEBAS =====" << std::endl;
    return 0;
}