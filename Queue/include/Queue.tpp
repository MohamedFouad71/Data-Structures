#pragma once
#include <iostream>
#include <optional>

template <typename T>
Queue<T>::Queue(int size) {

    if (size <= 0){
        std::cerr<<"Invalid size, initializing with a size of 100"<<std::endl;
        maxSize = 100;
    }
    else {
        maxSize = size;
    }

    length = front = 0;
    rear = maxSize - 1;
    arr = new T[maxSize];
}

template <typename T>
Queue<T>::~Queue(){
    delete[] arr;
}

template <typename T>
bool Queue<T>::isEmpty() const{
    return length == 0;
}

template <typename T>
bool Queue<T>::isFull() const{
    return length == maxSize;
}

template <typename T>
int Queue<T>::getCapacity() const{
    return maxSize;
}

template <typename T>
int Queue<T>::getLength() const{
    return length;
}

template <typename T>
void Queue<T>::enqueue(T item){

    if (isFull()){
        std::cerr<<"Error: Queue is Full\n";
        return;
    }
    ++length;
    rear = (++rear) % maxSize;
    arr[rear] = item;
}

template <typename T>
T Queue<T>::dequeue(){

    if (isEmpty()){
        std::cerr<<"Error: Queue is Empty\n";
        return T();
    }
    T item = arr[front];
    front = (++front) % maxSize;
    --length;
    return item;

}