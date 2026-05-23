//
// Created by derek on 16/05/2026.
//

#ifndef EJEMPLO_1_LISTITERATOR_H
#define EJEMPLO_1_LISTITERATOR_H

#include "Utilities/Utilities.h"
#include "Nodo.h"

//
// Rol en el patrón: ConcreteIterator
// ─────────────────────────────────────────────

template<class T>
class ConcreteIterator {
    public:
    ConcreteIterator(std::shared_ptr<Nodo<T>> start);
    bool hasNext();
    std::shared_ptr<T> getNext();
    private:
    std::shared_ptr<Nodo<T>> m_current;


};


template<class T>
ConcreteIterator<T>::ConcreteIterator(std::shared_ptr<Nodo<T>> head)
    : m_current(head) {}

template<class T>
bool ConcreteIterator<T>::hasNext() {
    return m_current != nullptr;
}

template<class T>
std::shared_ptr<T> ConcreteIterator<T>::getNext() {
    // Guardamos el elemento antes de avanzar
    std::shared_ptr<T> data = m_current->getElement();
    // Avanzamos al siguiente nodo
    m_current = m_current->getNext();
    return data;
}


#endif //EJEMPLO_1_LISTITERATOR_H