



#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main () {
    DoublyLinkedList<float> list1;
    list1.display();
    list1.insertLast(15.12);
    list1.display();
    list1.insertFirst(12.151);
    list1.display();
    list1.insertLast(10);
    list1.display();
    DoublyLinkedList<int> list3;
    list3.insertAt(0, 12);
    list3.display();
    list3.insertAt(1, 14);
    list3.display();
    list3.insertAt(1, 13);
    list3.display();
    list3.insertLast( 15);
    list3.display();
    list3.insertAt(1, 3);
    list3.display();
}