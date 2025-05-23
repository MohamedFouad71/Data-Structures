#pragma once
#include <iostream>

template <typename T>
Queue<T>::Queue(int size) {

    if (size <= 0){
        std::cerr<<"Invalid size, initializing with a size of 100"<<std::endl;
        maxSize = 100;
    }
    else {
        maxSize = size;
    }

    length = front = rear = 0;
    arr = new T[maxSize];
}

template <typename T>
Queue<T>::~Queue(){
    delete arr;
}

template <typename T>
bool Queue<T>::isEmpty(){
    return front == rear;
}

template <typename T>
int Queue<T>::size(){
    return maxSize;
}

template <typename T>
int Queue<T>::length(){
    return length;
}