#include "set.h"

template <typename T>
Set<T>::Set() {
    items = nullptr;
    size = 0;
}

template <typename T>
void Set<T>::add(T item) {
    T* temp = new T[size+1];
    for (int i = 0; i < size; i++) {
        temp[i] = items[i];
    }
    temp[size] = item;
    if (items != nullptr) {
        delete[] items;
    }
    items = temp;
    size++;
}

template <typename T>
int Set<T>::getSize() {
    return size;
}

template <typename T>
T* Set<T>::getArray()  {
    return items;
}