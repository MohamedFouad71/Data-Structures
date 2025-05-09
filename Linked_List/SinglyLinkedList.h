//
// Created by DELL on 04/05/2025.
//

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template <typename t>
struct node {
    t value;
    node *next;
};

template <typename t>
class SinglyLinkedList {
private:
    node<t> *first;
    node<t> *last;
    int length;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void display() const;
    int getLength() const;
    bool isEmpty() const;
    void setAt(int index, t value);
    void insertFirst(t value);
    void insertLast(t value);
    void insertAt(int index, t value);
    void removeFirst();
    void removeLast();
    void removeAt(int index);
    t getAt(int index) const;
    SinglyLinkedList operator+(const SinglyLinkedList &otherList);
};

#include "SinglyLinkedList.tpp"

#endif //SINGLYLINKEDLIST_H
