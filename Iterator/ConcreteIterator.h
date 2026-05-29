//
// Created by derek on 16/05/2026.
//

#ifndef EJEMPLO_1_LISTITERATOR_H
#define EJEMPLO_1_LISTITERATOR_H

#include "../Utilities/Utilities.h"
#include "IteratorInterface.h"
#include "Nodo.h"

template<class T>
class ConcreteIterator : public IteratorInterface<T> {
private:
    std::shared_ptr<Nodo<T>> current;
public:
    ConcreteIterator(std::shared_ptr<Nodo<T>> start);
    bool hasNext() override;
    void reset(std::shared_ptr<Nodo<T>>) override;
    std::shared_ptr<T> getNext() override;
};


template<class T>
ConcreteIterator<T>::ConcreteIterator(std::shared_ptr<Nodo<T>> start)
    : current(start) {}

template<class T>
bool ConcreteIterator<T>::hasNext() {
    return current != nullptr;
}

template<class T>
void ConcreteIterator<T>::reset(std::shared_ptr<Nodo<T>> start) { current = start; }

template<class T>
std::shared_ptr<T> ConcreteIterator<T>::getNext() {
    std::shared_ptr<T> data = current->getElement();
    current = current->getNext();
    return data;
}


#endif //EJEMPLO_1_LISTITERATOR_H