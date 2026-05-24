//
// Created by derek on 25/03/2026.
//

#ifndef PRACTICA_TEMPLATES_NODO_H
#define PRACTICA_TEMPLATES_NODO_H

#include "../Utilities/Utilities.h"
template<class T>
class Nodo {
private:
  std::shared_ptr<T> element;
  std::shared_ptr<Nodo<T>> next;
public:
  Nodo(std::shared_ptr<T> element,  std::shared_ptr<Nodo<T>> next);
  Nodo(std::shared_ptr<T> element);
  std::shared_ptr<Nodo<T>> getNext() const;
  std::shared_ptr<T> getElement();
  void setNext(std::shared_ptr<Nodo<T>> sig);
  void setElement(std::shared_ptr<T> element);
};

template<class T>
Nodo<T>::Nodo(std::shared_ptr<T> element,std::shared_ptr<Nodo<T>> next ){
  this->element = element;
  this->next = next;
}

template <class T>
Nodo<T>::Nodo(std::shared_ptr<T> element)
{
  this->element = element;
  this->next = nullptr;
}


template<class T>
std::shared_ptr<T> Nodo<T>::getElement() {
  return element;
}

template<class T>
std::shared_ptr<Nodo<T>> Nodo<T>::getNext() const {
  return next;
}

template<class T>
void Nodo<T>::setNext(std::shared_ptr<Nodo<T>> next) {
  this->next = next;
}

template<class T>
void Nodo<T>::setElement(std::shared_ptr<T>element) {
  this->element = element;
}



#endif //PRACTICA_TEMPLATES_NODO_H