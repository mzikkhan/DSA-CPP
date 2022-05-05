#include <iostream>
#include "SortedList.h"
using namespace std;

template <class T>
SortedList<T> :: SortedList(){
    length = 0;
    currentPos = -1;
    capacity = 10;
    list = new T[capacity];
}

template <class T>
SortedList<T> :: SortedList(int capacity){
    length = 0;
    currentPos = -1;
    this->capacity = capacity;
    list = new T[capacity];
}

template <class T>
void SortedList<T> :: makeEmpty(){
    length = 0;
}

template <class T>
bool SortedList<T> :: isFull(){
    return (length == capacity);
}

template <class T>
int SortedList<T> :: lengthIs(){
    return length;
}

template <class T>
void SortedList<T> :: resetList(){
    currentPos = -1;
}

template <class T>
void SortedList<T> :: insertItem(T item){
    int location = 0;
    while(location < length){
        if(item > list[location]){
            location++;
        }else{
            break;
        }
    }
    for(int i=length; i>location; i--){
        list[i] = list[i-1];
    }
    list[location] = item;
    length++;
}

template <class T>
T SortedList<T> :: getNextItem(){
    currentPos++;
    return list[currentPos];
}

template <class T>
bool SortedList<T> :: searchItem(T item){
    int midPoint, first = 0;
    int last = length - 1;
    while(first <= last){
        midPoint = (first+last)/2;
        if(item == list[midPoint]){
            return 1;
        }else if(item < list[midPoint]){
            last = midPoint - 1;
        }else if(item > list[midPoint]){
            first = midPoint+1;
        }
    }
    return 0;
}

template <class T>
void SortedList<T> :: deleteItem(T item){
    int location = 0;
    while(item != list[location]){
        location++;
    }
    for(int i=location +1; i<length; i++){
        list[i-1] = list[i];
    }
    length--;
}

