#include <iostream>
#include <string>
#include <cassert>
#include "stack.hpp"

using namespace std;

int main() {
    // Test with integers
    cout << "Testing integer stack..." << endl;
    stack<int> intStack;

    // Test isEmpty and getLength on empty stack
    assert(intStack.isEmpty() == true);
    assert(intStack.getLength() == 0);
    cout << "Empty stack tests passed." << endl;

    // Test push and getTop
    intStack.push(10);
    assert(intStack.getTop() == 10);
    assert(intStack.isEmpty() == false);
    assert(intStack.getLength() == 1);
    cout << "Single element push/getTop tests passed." << endl;

    // Test multiple pushes
    intStack.push(20);
    intStack.push(30);
    assert(intStack.getTop() == 30);
    assert(intStack.getLength() == 3);
    cout << "Multiple push tests passed." << endl;

    // Test pop
    intStack.pop();
    assert(intStack.getTop() == 20);
    assert(intStack.getLength() == 2);
    cout << "Pop test passed." << endl;

    // Test isFull (we'll push until full)
    cout << "Filling stack..." << endl;
    for (int i = 0; !intStack.isFull(); i++) {
        intStack.push(i);
    }
    assert(intStack.isFull() == true);
    assert(intStack.getLength() == intStack.getSize());
    cout << "Stack full test passed." << endl;

    // Test overflow message
    cout << "Expect stack full message:" << endl;
    intStack.push(999);  // Should show error message

    // Test empty stack behavior
    stack<int> emptyStack;
    cout << "Expect stack empty message:" << endl;
    emptyStack.pop();    // Should show error message
    cout << "Expect stack empty message:" << endl;
    int val = emptyStack.getTop();  // Should show error message and return default int (0)
    assert(val == 0);

    // Test with strings
    cout << "\nTesting string stack..." << endl;
    stack<string> strStack;
    strStack.push("hello");
    strStack.push("world");
    assert(strStack.getTop() == "world");
    strStack.pop();
    assert(strStack.getTop() == "hello");
    cout << "String stack tests passed." << endl;

    cout << "\nAll tests passed successfully!" << endl;
    return 0;
}