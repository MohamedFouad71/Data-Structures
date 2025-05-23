#include <iostream>
using namespace std;

template <class t>
class stack{

    static const int maxSize = 100;
    int top; // points to the next available place
    t arr[maxSize];

    public:

    stack(){
        top = -1;
    }

    bool isEmpty() const{
        return top == -1;
    }

    bool isFull() const{
        return top == maxSize-1;
    }

    int getLength() const{
        return top + 1;
    }

    int getSize() const{
        return maxSize;
    }

    void push(t value){

        if (isFull())
            cerr<<"Stack is Full\n";
        else{
            arr[++top] = value; 
        }

    }

    void pop(){
        if (isEmpty())
            cerr<<"Stack is Empty\n";
        else{
            return arr[top--];
        }
    }

    t getTop() const{
        if (isEmpty()){
            cerr<<"Stack is Empty!!\n";
            return t();
        }
        return arr[top];
    }

};

int main(){
    stack <int> newstack;
    newstack.push(1);
    cout<<newstack.getTop();
    return 0;
}