#pragma once

template <typename T>
class StackItem {
    T _data;
    StackItem<T>* _next;

public:
    StackItem(T data) : _data(data), _next(nullptr) {}
    void setNext(StackItem<T>* next) {
        _next = next;
    }
    T& getData() { return _data; }
    StackItem<T>* getNext() { return _next; }
    ~StackItem() {
        delete _data;
        _next = nullptr;
    }
};

template<typename T>
class AListIterator
{
public:
    AListIterator(StackItem<T>* values_ptr) : _item{ values_ptr } {}

    bool operator!=(const AListIterator<T>& other) const
    {
        return this->_item != dynamic_cast<const AListIterator&>(other)._item;
    }

    bool operator==(const AListIterator<T>& other) const
    {
        return this == other;
    }

    AListIterator& operator++()
    {
        _item = _item->getNext();
        return *this;
    }

    T& operator*() const
    {
        return _item->getData();
    }

private:
    StackItem<T>* _item;
};

template <typename T>
class AList {

protected:
    StackItem<T>* _first;
    StackItem<T>* _last;

private:
    unsigned int _max_size;
    unsigned int _size;

public:
    AList(unsigned int max_size);
    AList();
    void vypisZasobnika();
    unsigned int size() const;
    unsigned int getMaxSize() const;
    bool isEmpty() const;
    bool isFull() const;
    bool pushFront(T data);
    bool push(T data);

    void setMaxCapacity(unsigned int max_size);

    T& get(unsigned int index) const;

    T pop();
    T accessData();
    void clear();
    ~AList();
    typedef AListIterator<T> iterator;
    typedef AListIterator<const T> const_iterator;
    iterator begin();
    iterator end();

    void incSize();
    const T& accessLast() const;
    const T& accessFirst() const;
};

template <typename T>
inline T& AList<T>::get(unsigned int index) const {
    unsigned char vIndex = 0;
    StackItem<T>* vItem = _first;
    while (index != vIndex && index < 256) {
        vItem = vItem->getNext();
        vIndex++;
    }
    return vItem->getData();
}

template <typename T>
inline void AList<T>::setMaxCapacity(unsigned int capacity) {
    _max_size = capacity;
}

template <typename T>
typename AList<T>::iterator AList<T>::begin() {
    return iterator(_first);
}

template <typename T>
typename AList<T>::iterator AList<T>::end() {
    return iterator(nullptr);
}

template <typename T>
inline AList<T>::AList(unsigned int max_size) : _max_size(max_size), _first(nullptr), _last(nullptr), _size(0) {};

template <typename T>
inline AList<T>::AList() : _max_size(0), _first(nullptr), _last(nullptr), _size(0) {};


template <typename T>
inline void AList<T>::vypisZasobnika() {
    StackItem<T>* var = _first;
    while (var != nullptr) {     
        var = var->getNext();        
    }
}

template <typename T>
inline void AList<T>::incSize() {
    ++_size;
}

template <typename T>
inline const T& AList<T>::accessLast() const {
    return _last->getData();
}

template <typename T>
inline const T& AList<T>::accessFirst() const {
    return _first->getData();
}

template <typename T>
inline unsigned int AList<T>::size() const {
    return _size; 
}

template <typename T>
inline unsigned int AList<T>::getMaxSize() const {
    return _max_size;
}

template <typename T>
inline bool AList<T>::isEmpty() const {
    return _size == 0 ? 1 : 0;
}

template <typename T>
inline bool AList<T>::isFull() const {
    return _size == _max_size ? 1 : 0;
}

template <typename T>
inline bool AList<T>::pushFront(T data) {
    if (_size + 1 > _max_size) {
        return false;
    }
    StackItem<T>* temp = new StackItem<T>(data);
    if (!_first) {
        _last = temp;
    }
    else {
        temp->setNext(_first);
    }
    _first = temp;
    ++_size;
    return true;
}

template <typename T>
inline bool AList<T>::push(T data) { // push back
    if (_size + 1 > _max_size) {
        return false;
    }
    StackItem<T>* temp = new StackItem<T>(data);
    if (!_first) {
        _first = temp;
    }
    else {
        _last->setNext(temp);
    }
    _last = temp;
    ++_size;
    return true;
}

template <typename T>
inline T AList<T>::pop() {
    if (!_first) {
        return nullptr;
    }
    T firstData = _first->getData();
    StackItem<T>* temp = _first;
    _first = _first->getNext();
    delete temp;
    --_size;
    return firstData;
}

template <typename T>
inline T AList<T>::accessData() {
    return _first->getData();
}

template <typename T>
inline void AList<T>::clear() {
    while (_first) {
        StackItem<T>* var = _first;
        _first = _first->getNext();
        --_size;
        delete var;
    }
}

template <typename T>
inline AList<T>::~AList() {
    clear();
    _first = nullptr;
    _last = nullptr;
}


