// Please be aware that certain compilers may encounter issues when using cerr.
// If you experience this problem, consider switching to a different compiler.
// Kindly note that this is not a coding error.
// If you encounter any other issues, feel free to contact me.

#include <iostream>
#include "Darray.H"

int main() {
    // Test 1: Create an array with a fixed size
    Array<int> arr1(5);
    std::cout << "Array1 created with size: " << arr1.getSize() << std::endl;

    // Test 2: Set values
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    arr1.set(3, 40);
    arr1.set(4, 50);
    std::cout << "Array1 after setting values From 10 to 50 by step 10 : ";
    arr1.display();

    // Test 3: Get values
    std::cout << "Value at index 2: " << arr1.get(2) << std::endl;  // Should print 30
    std::cout << "Value at index 4: " << arr1.get(4) << std::endl;  // Should print 50

    // Test 4: Negative index handling (set and get)
    arr1.set(-1, 60); // Set value at the last position using negative index
    std::cout <<"Setting Array1[-1] to 60"<<std::endl
              << "Value at index -1: " << arr1.get(-1) << std::endl;  // Should print 60

    // Test 5: Remove a value
    arr1.remove(2);  // Remove value at index 2
    std::cout << "Array after removing value at index 2: ";
    arr1.display();  // Should not show the value 30 at index 2 anymore


    // Test 6: Merge two arrays
    Array<int> arr2(3);
    arr2.set(0, 100);
    arr2.set(1, 200);
    arr2.set(2, 300);
    std::cout << "Second array: ";
    arr2.display();

    Array<int> mergedArr = arr1.merge(arr2);
    std::cout << "Merged array: ";
    mergedArr.display();


    // Test 7: Handle Out of bond errors
    std::cout << "Setting a value out of bounds: "<<std::endl;
    arr1.set(-10 , 20);
    std::cout << "Getting a value out of bounds: "<<std::endl;
    arr1.get(-10 );

    return 0;
}
