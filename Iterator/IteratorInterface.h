//
// Created by kris on 26/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_ITERATORINTERFACE_H
#define PROYECTO_2___KRIS_Y_DEREK_ITERATORINTERFACE_H

#include <memory>

template <class T>
class IteratorInterface {
public:
    virtual bool hasNext() = 0;
    virtual void reset(std::shared_ptr<Nodo<T>>) = 0;
    virtual std::shared_ptr<T> getNext() = 0;
};


#endif //PROYECTO_2___KRIS_Y_DEREK_ITERATORINTERFACE_H