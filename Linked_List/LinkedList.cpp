#include <iostream>
using namespace std;

template <typename t>
struct node{
    t value;
    node<t>* next;
    node(t val) : value(val) , next(nullptr){}
};

template <class t>
class LinkedList{
    private:
    node* head;

    public:
    LinkedList(t val){
        node<t> newNode;
        head = &newNode
    }

    void addFirst(t val){
        
    }
};