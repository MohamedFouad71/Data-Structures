#include <Cmath>

#include "Darray.h"

template <typename t>
Darray<t>::Darray(int arrSize){

    length = 0;
    this->size = arrSize;
    accessingPtr = new t[arrSize];
    for (size_t i = 0; i < arrSize ; i++){
        accessingPtr[i] = t();
    }
}

template <typename t>
Darray<t>::~Darray() {
    delete[] accessingPtr;
}

template<class t>
bool Darray<t>::isFull() const {
    return length == size;
}

template<class t>
bool Darray<t>::isEmpty() const {
    return length == 0;
}

template<typename t>
void Darray<t>::set(int index, t value){
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

    if (accessingPtr[actualIndex] == t()) {
        length++;
    }

    accessingPtr[actualIndex] = value;
}

template<typename t>
t Darray<t>::getValue (int index) const {
    if (index >= 0 && index < size)
        return accessingPtr[index];
    else if (index < 0 && (size + index) >= 0)
        return accessingPtr[size + index];
    else {
        std::cerr << "index out of bounds" << std::endl;
        return NAN;
    }
}

template<typename t>
void Darray<t>::remove(int index) {
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

    if (accessingPtr[actualIndex] == t()) {
        std::cerr << "[Warning] Element at index " << index << " is already default. Nothing to remove." << std::endl;
        return;
    }

    accessingPtr[actualIndex] = t();  // Reset to default value
    length--;
}

template <typename t>
int Darray<t>::getSize() const {
    return size;
}

template <typename t>
int Darray<t>::getLength() const {
    return length;
}

template <typename t>
void Darray<t>::display() const {

    std::cout<<"[";

    for (size_t i = 0; i < size; i++) {

        if (i == size - 1)
            std::cout<<accessingPtr[i]<<"]"<<std::endl;
        else
            std::cout<<accessingPtr[i]<<" , ";
    }

}

template <typename t>
Darray<t> Darray<t>::merge(const Darray<t>& arr2) {

    int mergedSize = this->size + arr2.getSize();
    Darray merged(mergedSize);

    for (size_t i = 0; i < this->size; i++) {
        merged.set(i, this->getValue(i));
    }

    for (size_t i = 0; i < arr2.getSize(); i++) {
        merged.set(this->size + i, arr2.getValue(i));
    }

    return merged;
}

template<typename t>
void Darray<t>::extend(int newsize) { // O(n)
    if (newsize <= this->size) {
        std::cerr<<"Error, New size is not larger than the old one";
        return;
    }
    t *NewArr = new t[newsize];
    for (size_t i = 0; i < this->size ; i++) {
        NewArr[i] = accessingPtr[i];
    }
    delete[] accessingPtr;
    accessingPtr = NewArr;
    for (size_t i = this->size ; i < newsize ; i++){
        accessingPtr[i] = t();
    }
    size = newsize;
}

template<class t>
void Darray<t>::insertAt(int index, t value) {

    if (isFull()) {
        std::cerr<<"Array is Full\n";
        return;
    }

    if (index < 0 || index > size) {
        std::cerr << "Invalid index\n";
        return;
    }

    for (size_t i = size ; i > index ; i--) {
        accessingPtr[i] = accessingPtr[i - 1];
    }

    accessingPtr[index] = value;
    length++;
}
