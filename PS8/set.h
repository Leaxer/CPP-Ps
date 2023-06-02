#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

template <typename T>
class Set {
    public:
        Set();
        void add(T item);
        int getSize();
        T* getArray();
    private:
        T* items;
        int size;
};

#endif