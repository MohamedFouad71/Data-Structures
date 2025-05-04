#ifndef DARRAY_H
#define DARRAY_H


template <class t>
class Darray
{
private:
    int size; // reserved places
    t* accessingPtr; //ptr for accessing data stored in heap
    int length; // number of assigned indexes

public:

    Darray(int arrSize);
    ~Darray();
    // Returns True if the array is full
    bool isFull() const;
    // Returns True if the array is empty
    bool isEmpty() const;
    // Set the value of a specific index
    void set(int index , t value);
    // Get the value of a specific index
    t getValue (int index) const;
    // Remove a value from an index
    void remove(int index) ;
    // Returns the size of the array
    int getSize() const;
    // Returns the number of elements in an array
    int getLength() const;
    // Display the whole array
    void display() const;
    // Merges two arrays and stores the value in the first one
    Darray<t> merge(const Darray<t>& arr2);
    // Extends the size of an array
    void extend(int size);
    // Inserts a value in a specific index
    void insertAt(int index , t value);
};




#include "Darray.tpp"

#endif