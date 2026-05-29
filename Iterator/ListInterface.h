//
// Created by kris on 26/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_INTERFACELIST_H
#define PROYECTO_2___KRIS_Y_DEREK_INTERFACELIST_H

template<class T> class List;
#include "ConcreteIterator.h"
#include "../Utilities/Utilities.h"



template <class T>
class ListInterface {
public:

    virtual void insertFirst(std::shared_ptr<T>) = 0;
    virtual void insertLast(std::shared_ptr<T> element) = 0;
    virtual bool isEmpty() = 0;
    virtual void deleteElement(std::shared_ptr<T>) = 0;
    virtual std::shared_ptr<Nodo<T>> getFirst() const = 0;
    virtual int length() = 0;
    virtual std::string showList() = 0;
    virtual std::shared_ptr<List<T>> clone() const = 0;


    virtual std::shared_ptr<IteratorInterface<T>> createIterator() = 0;
};


#endif //PROYECTO_2___KRIS_Y_DEREK_INTERFACELIST_H