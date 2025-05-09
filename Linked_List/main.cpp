#include <iostream>
#include "SinglyLinkedList.h"

int main() {
    // Insert and set test
    SinglyLinkedList<float> ll1; // created new empty list
    std::cout<<"New empty list created :";
    ll1.display();
    std::cout<<"Adding 5 : ";
    ll1.insertLast(5);
    ll1.display();
    std::cout<<"Adding 4 first : ";
    ll1.insertFirst(4);
    ll1.display();
    std::cout<<"Adding 6 last : ";
    ll1.insertLast(6);
    ll1.display();
    std::cout<<"changing index 1 to 2 : ";
    ll1.setAt(1 , 2);
    ll1.display();
    std::cout<<"changing index -1 to 1 : ";
    ll1.setAt(-1 , 1);
    ll1.display();
    std::cout<<"Inserting 12 at index 1 : ";
    ll1.insertAt(1 ,12);
    ll1.display();
    std::cout<<"Removing value of index 1 : ";
    ll1.removeAt(1);
    ll1.display();
}