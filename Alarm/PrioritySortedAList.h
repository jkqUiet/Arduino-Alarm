#pragma once

#include "AList.h"

template <typename T>
class PriorityItem : public StackItem<T> {
    unsigned int _priority;
public:
    PriorityItem(unsigned int priority, T value);
    const unsigned int getPriority()const;
    void setPriority(unsigned int priority);
};

template <typename T>
PriorityItem<T>::PriorityItem(unsigned int priority, T data) : StackItem<T>(data), _priority(priority) {
}

template <typename T>
const unsigned int PriorityItem< T>::getPriority() const {
    return _priority;
}

template <typename T>
void PriorityItem<T>::setPriority(unsigned int priority) {
    _priority = priority;
}

template <typename T>
class PrioritySortedAList : public AList<PriorityItem<T>*> {

    AList<PriorityItem<T>*>* _list;
public:
	PrioritySortedAList(unsigned int capacity);
    ~PrioritySortedAList();
    T pop();
    void clear();
    T peekItem();
    bool insert(unsigned int priority, T data);
    unsigned int getMaxPriority();
};

template <typename T>
inline PrioritySortedAList<T>::PrioritySortedAList(unsigned int capacity)
{
    _list = new AList<PriorityItem<T>*>();
    _list->setMaxCapacity(capacity);
}

template <typename T>
inline PrioritySortedAList<T>::~PrioritySortedAList() {
    clear();
    delete _list;
}

template <typename T>
inline bool PrioritySortedAList<T>::insert(unsigned int priority, T data) {
    if (_list->isFull()) return false;
    PriorityItem<T>* item = new PriorityItem<T>(priority, data);
    PriorityItem<T>* varActual = _list->AList<PriorityItem<T>*>::accessFirst();
    if (varActual->getPriority() < priority) {
        _list->pushFront(item);
        return true;
    }
    varActual = _list->AList<PriorityItem<T>*>::accessLast();
    if (varActual->getPriority() > priority) {
        _list->push(item);
        return true;
    }
    varActual = _list->AList<PriorityItem<T>*>::accessFirst();
    while (varActual != nullptr && varActual->getPriority() > priority) {
        varActual = varActual->getNext();
    }
    if (varActual != nullptr) {
        item->setNext(varActual->getNext());
        varActual->setNext(item);
        _list->incSize();
        return true;
    }
}

template <typename T>
inline T PrioritySortedAList<T>::peekItem() {
    T data;
    PriorityItem<T>* item = _list->pop();
    data = item->getData();
    delete item;
    return data;
}

template <typename T>
inline void PrioritySortedAList<T>::clear() {
    for (PriorityItem<T>* item : _list) {
        delete item;
    }
    _list->clear();
}

template <typename T>
inline unsigned int PrioritySortedAList<T>::getMaxPriority() {
    return _list->accessFirst()->getPriority();
}