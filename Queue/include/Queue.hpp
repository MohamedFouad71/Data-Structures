#pragma once

template <class T>
class Queue{

    int front , rear , length , maxSize;
    T *arr;
    
    public:
    explicit Queue(int size = 100);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int getCapacity() const;
    int getLength() const;
    void enqueue(T item);
    T dequeue();
};



#include "Queue.tpp"