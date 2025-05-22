#include <iostream>
#include "Queue.hpp"  

int main() {
    Queue<int> q(5);

    std::cout << "Enqueue 3 elements:\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Size: " << q.getLength() << "\n";
    std::cout << "Capacity: " << q.getCapacity() << "\n";

    std::cout << "\nDequeue elements:\n";
    for (int i = 0; i < 4; ++i) {
        int val = q.dequeue(); // لو الكيو فاضي، هيرجع 0
        std::cout << "Dequeued: " << val << "\n";
    }

    std::cout << "\nTesting wrap-around:\n";
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);  

    while (!q.isEmpty()) {
        std::cout << "Dequeued: " << q.dequeue() << "\n";
    }

    return 0;
}
