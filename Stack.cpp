#include "Stack.h"
#include <iostream>

using namespace std;


Stack :: Stack(){
    stackSize = 5;
    items = new int[stackSize];
    topIndex = -1;
}


Stack :: Stack(int stackSize){
    this->stackSize = stackSize;
    items = new int[stackSize];
    topIndex = -1;
}


Stack :: ~Stack(){
    delete[]items;
}


void Stack :: makeEmpty(){
    topIndex = -1;
}


bool Stack :: isFull(){
    return (topIndex == stackSize-1);
}

bool Stack :: isEmpty(){
    return (topIndex == -1);
}

void Stack :: push(int newItem){
    if(isFull()){
        throw FullStack();
    }
    topIndex++;
    items[topIndex] = newItem;
}

void Stack :: pop(int& item){
    if(isEmpty()){
        throw EmptyStack();
    }
    item = items[topIndex];
    topIndex--;
}

int Stack :: top(){
    if(isEmpty()){
        throw EmptyStack();
    }
    return items[topIndex];
}


















//
