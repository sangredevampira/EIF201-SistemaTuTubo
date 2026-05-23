//
// Created by derek on 21/05/2026.
//

#include "List.h"
#include "ConcreteIterator.h"



int main() {
    std::cout << "===== PRUEBA PATRON ITERADOR =====" << std::endl << std::endl;

    // Crear una lista de integers
    auto listaNumeros = std::make_shared<List<int>>();

    // Insertar números
    std::cout << "Insertando números..." << std::endl;
    listaNumeros->insertLast(std::make_shared<int>(10));
    listaNumeros->insertLast(std::make_shared<int>(20));
    listaNumeros->insertLast(std::make_shared<int>(30));
    listaNumeros->insertLast(std::make_shared<int>(40));
    listaNumeros->insertLast(std::make_shared<int>(50));

    std::cout << "Total de elementos: " << listaNumeros->length() << std::endl << std::endl;

    // Mostrar lista
    std::cout << "===== LISTADO DE NUMEROS =====" << std::endl;
    std::cout << listaNumeros->showList() << std::endl;

    // Usar el iterador para recorrer y procesar
    std::cout << "===== RECORRIDO CON ITERADOR =====" << std::endl;
    auto iterador = listaNumeros->createIterator();

    int suma = 0;
    int contador = 1;
    while (iterador->hasNext()) {
        auto numero = iterador->getNext();
        std::cout << "Elemento " << contador << ": " << *numero << std::endl;
        suma += *numero;
        contador++;
    }

    std::cout << std::endl << "Suma total: " << suma << std::endl;

    // Segunda lista con strings
    std::cout << std::endl << "===== LISTA DE STRINGS =====" << std::endl;
    auto listaTextos = std::make_shared<List<std::string>>();

    listaTextos->insertLast(std::make_shared<std::string>("Primer elemento"));
    listaTextos->insertLast(std::make_shared<std::string>("Segundo elemento"));
    listaTextos->insertLast(std::make_shared<std::string>("Tercer elemento"));

    std::cout << "Total de strings: " << listaTextos->length() << std::endl << std::endl;
    std::cout << listaTextos->showList() << std::endl;

    // Iterador para strings
    std::cout << "===== RECORRIDO DE STRINGS CON ITERADOR =====" << std::endl;
    auto iteradorStrings = listaTextos->createIterator();

    int pos = 1;
    while (iteradorStrings->hasNext()) {
        auto texto = iteradorStrings->getNext();
        std::cout << pos << ". " << *texto << " (Longitud: " << texto->length() << ")" << std::endl;
        pos++;
    }

    std::cout << std::endl << "===== FIN =====" << std::endl;
    return 0;
}