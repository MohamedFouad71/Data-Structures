#pragma once

template <class T>
class Queue{

    int front , rear , length , maxSize;
    T *arr;
    
    public:
    Queue(int size = 100);
    ~Queue();
    bool isEmpty();
    int size();
    void enqueue(T item);
    T dequeue();
};



#include "Queue.tpp"