//
// Created by derek on 25/03/2026.
//

#ifndef PRACTICA_TEMPLATES_LISTA_H
#define PRACTICA_TEMPLATES_LISTA_H


#include "Nodo.h"
#include "ListInterface.h"
#include "ConcreteIterator.h"

template<class T>
class List : ListInterface<T> {
private:
    std::shared_ptr<Nodo<T>> first;
public:
    List();
    void insertFirst(std::shared_ptr<T>);
    void insertLast(std::shared_ptr<T> element);
    bool isEmpty();
    void deleteElement(std::shared_ptr<T>);
    std::shared_ptr<Nodo<T>> getFirst() const;
    int length();
    std::string showList();
    std::shared_ptr<List<T>> clone() const;
    std::shared_ptr<IteratorInterface<T>> createIterator();
};

template<class T>
List<T>::List() {
    first = nullptr;
}

template<class T>
bool List<T>::isEmpty() {
    return (first == nullptr);
}

template<class T>
void List<T>::insertFirst(std::shared_ptr<T> dato) {
    first = std::make_shared<Nodo<T>>(dato, first);
}

template <class T>
void List<T>::insertLast(std::shared_ptr<T> element)
{

    auto newNode = std::make_shared<Nodo<T>>(element);

    if (this->first == nullptr)
    {
        this->first = newNode;
    }
    else
    {
        auto current = this->first;

        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }

        current->setNext(newNode);
    }
}


template<class T>
std::shared_ptr<Nodo<T>> List<T>::getFirst() const{
    return first;
}

template <class T>
int List<T>::length()
{
    int length = 0;
    std::shared_ptr<Nodo<T>> temp = first;
    while (temp != nullptr)
    {
        length++;
        temp = temp->getNext();
    }
    return length;
}

template <class T>
std::string List<T>::showList()
{
    std::stringstream ss;
    std::shared_ptr<Nodo<T>> temp = first;
    int i = 1;
    while (i <= length())
    {
        ss << i << ". " << *temp->getElement() << "\n";

        temp = temp->getNext();
        i++;
    }
    return ss.str();
}

template <class T>
std::shared_ptr<List<T>> List<T>::clone() const
{
    auto newList = std::make_shared<List<T>>();
    auto current = this->getFirst();

    while (current != nullptr)
    {
        newList->insertLast(current->getElement());
        current = current->getNext();
    }

    return newList;
}

template<class T>
void List<T>::deleteElement(std::shared_ptr<T> target) {
    if (isEmpty()) {
        return;
    }
    std::shared_ptr<Nodo<T>> temp = first;

    if (temp->getElement() == target) {
        first = temp->getNext();
        return;
    }
    std::shared_ptr<Nodo<T>> prev = temp;
    std::shared_ptr<Nodo<T>> curr = temp->getNext();
    while (curr != nullptr) {
        if (curr->getElement() == target) {
            prev->setNext(curr->getNext());
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }
}

template<class T>
std::shared_ptr<IteratorInterface<T>> List<T>::createIterator() {
    return std::make_shared<ConcreteIterator<T>>(this->first);
}


#endif //PRACTICA_TEMPLATES_LISTA_H
