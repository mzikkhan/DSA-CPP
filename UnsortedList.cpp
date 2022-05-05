#include <iostream>
#include "UnsortedList.h"
using namespace std;

template <class T>
UnsortedList<T> :: UnsortedList(){
    length = 0;
    currentPos = -1;
    capacity = 10;
    list = new T[capacity];
}

template <class T>
UnsortedList<T> :: UnsortedList(int capacity){
    length = 0;
    currentPos = -1;
    this->capacity = capacity;
    list = new T[capacity];
}

template <class T>
void UnsortedList<T> :: makeEmpty(){
    length = 0;
}

template <class T>
bool UnsortedList<T> :: isFull(){
    return (length == capacity);
}

template <class T>
int UnsortedList<T> :: lengthIs(){
    return length;
}

template <class T>
void UnsortedList<T> :: resetList(){
    currentPos = -1;
}

template <class T>
void UnsortedList<T> :: insertItem(T item){
    list[length] = item;
    length++;
}

template <class T>
T UnsortedList<T> :: getNextItem(){
    currentPos++;
    return list[currentPos];
}

template <class T>
void UnsortedList<T> :: searchItem(T &item, bool &found){
    int location = 0;
    bool Search = (location < length);
    found = false;
    while (Search && !found){
        if(item == list[location]){
            found = true;
            item = list[location];
        }else{
            location++;
            Search = (location < length);
        }
    }
}

template <class T>
void UnsortedList<T> :: deleteItem(T item){
    int location = 0;
    while(item != list[location]){
        location++;
    }
    list[location] = list[length-1];
    length--;
}
