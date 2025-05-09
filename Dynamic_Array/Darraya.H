#include <iostream>
#include <cmath>
template <class t>
class Array {

private:
    int size; // reserved places
    t* accessing_ptr; //ptr for accessing data stored in heap
    int length; // number of assigned indexes

public:

    Array(int arrSize) {
        length = 0;
        this->size = arrSize;
        accessing_ptr = new t[arrSize];
        for (size_t i = 0; i < arrSize ; i++) {
            accessing_ptr[i] = t();
        }
    }

    ~Array() {
        delete[] accessing_ptr;
    }

    // setting a value (supports negative indexing)
    void set(int index , t value) {
        int actualIndex;


        if (index >= 0 && index < size) {
            actualIndex = index;
        }
        else if (index < 0 && (size + index) >= 0) {
            actualIndex = size + index;
        }
        else {
            std::cerr << "index out of bounds" << std::endl;
            return;
        }

        if (accessing_ptr[actualIndex] == t()) {
            length++;
        }

        accessing_ptr[actualIndex] = value;
    }


    // fetching a value (supports negative indexing)
    t get (int index) const {
        if (index >= 0 && index < size)
            return accessing_ptr[index];
        else if (index < 0 && (size + index) >= 0)
            return accessing_ptr[size + index];
        else {
            std::cerr << "index out of bounds" << std::endl;
        }
    }

    // Removes a value by index (supports negative indexing)
    void remove(int index) {
        int actualIndex;

        if (index >= 0 && index < size) {
            actualIndex = index;
        }
        else if (index < 0 && (size + index) >= 0) {
            actualIndex = size + index;
        }
        else {
            std::cerr << "[Error] Index out of bounds in remove()." << std::endl;
            return;
        }

        if (accessing_ptr[actualIndex] == t()) {
            std::cerr << "[Warning] Element at index " << index << " is already default. Nothing to remove." << std::endl;
            return;
        }

        accessing_ptr[actualIndex] = t();  // Reset to default value
        length--;
    }

    // gets the size reserved
    int getSize() const {
        return size;
    }

    // gets the number of values set
    int getLength() const {
        return length;
    }

    // Displaying the whole array in this format [val1 , val2 ... ]
    void display() const {

        std::cout<<"[";

        for (size_t i = 0; i < size; i++) {

            if (i == size - 1)
                std::cout<<accessing_ptr[i]<<"]"<<std::endl;
            else
                std::cout<<accessing_ptr[i]<<" , ";
        }

    }
    // Merges two arrays of the same type
    Array merge(const Array<t>& arr2) {

        int mergedSize = this->size + arr2.getSize();
        Array merged(mergedSize);

        for (size_t i = 0; i < this->size; i++) {
            merged.set(i, this->get(i));
        }

        for (size_t i = 0; i < arr2.getSize(); i++) {
            merged.set(this->size + i, arr2.get(i));
        }

        return merged;
    }
};




// testing
// int main() {
//     // Declarati
//     Array<int> arr1(5);
//     arr1.display();
//     arr1.set(5 , 5);
//     arr1.display();
//     std::cout<<arr1.get(0)<<std::endl;
//     std::cout<<arr1.getLength();
//
// }

