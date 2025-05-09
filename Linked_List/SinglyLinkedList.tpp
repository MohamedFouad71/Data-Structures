//
// Created by DELL on 04/05/2025.
//
#pragma once


#include "SinglyLinkedList.h"
#include <iostream>
// --------------------------------- Constructor And Destructor --------------------------------------

template<typename t>
SinglyLinkedList<t>::SinglyLinkedList() : first(nullptr) , last(nullptr) , length(0){ }

template<typename t>
SinglyLinkedList<t>::~SinglyLinkedList() {

}
// ------------------------------------ Display --------------------------------------------

template<typename t>
void SinglyLinkedList<t>::display() {

    std::cout << "[";

    node<t>* temp = first;
    while (temp != nullptr) {
        std::cout << temp->value;
        if (temp->next != nullptr) {
            std::cout << " , ";
        }
        temp = temp->next;
    }

    std::cout << "]\n";
}

template<typename t>
int SinglyLinkedList<t>::getLength() {
    return length;
}

template<typename t>
bool SinglyLinkedList<t>::isEmpty() {
    return length == 0;
}

// ---------------------------------- Set At -------------------------------------

template<typename t>
void SinglyLinkedList<t>::setAt(int index, t value) {

    node<t> *temp = first;

    // For including negative index
    int actualIndex;
    if (index > 0 && index < length ) {
        actualIndex = index;
    }
    else if (index < 0 && abs(index) <= length ) {
        actualIndex = length + index;
    }
    else {
        std::cerr<<"Error, index is out of range";
        return;
    }

    for (size_t i = 0; i < actualIndex; i++) {
        temp = temp->next;
    }

    temp->value = value;
}

// -------------------------------- Insert First ---------------------------------------

template<typename t>
void SinglyLinkedList<t>::insertFirst(t value) {

    node<t> *newNode = new node<t>;
    if (length == 0) {
        last = newNode;
        newNode->next = nullptr;
    }
    else {
        newNode->next = first;
    }
    first = newNode;
    newNode->value = value;
    length++;
}
// --------------------------------- Insert Last --------------------------------------

template<typename t>
void SinglyLinkedList<t>::insertLast(t value) {

    auto *newNode = new node<t>; // node creation

    if (length == 0) {
        first = newNode;
    }
    else {
        last->next = newNode;
    }

    last = newNode;
    newNode->value = value;
    newNode->next = nullptr;
    length++;
}
// --------------------------------- Insert At --------------------------------------

template<typename t>
void SinglyLinkedList<t>::insertAt(int index , t value) {

    if (index == 0) {
        insertFirst(value);
        return;
    }

    if (index == length) {
        insertLast(value);
        return;
    }

    if (index < 0 || index >= length ) {
        std::cerr<<"Error, index is out of range\n";
        return;
    }

    node<t> *temp = first;
    // Making temp point at the node before the new node
    for (size_t i = 1 ; i < index  ; i++) {
        temp = temp->next;
    }

    auto *newNode = new node<t>;
    newNode->next = temp->next;
    newNode->value = value;
    temp->next = newNode;
    length++;
}

template<typename t>
void SinglyLinkedList<t>::removeAt(int index) {

    if (isEmpty()) {
        std::cerr<<"The list is empty\n";
    }
    if (index < 0 || index >= length ) {
        std::cerr<<"Error, index is out of range\n";
        return;
    }

    if (index == 0) {
        node<t> *temp = first;
        first = first->next;
        delete temp;
        return;
    }

    node<t> *current = first;
    // Making current point at the node before the new node
    for (size_t i = 1 ; i < index  ; i++) {
        current = current->next;
    }
    node<t> *temp = current->next; // storing the value to delete it
    current->next = current->next->next;
    delete temp;
}






