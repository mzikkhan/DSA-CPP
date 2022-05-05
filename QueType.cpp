#include <iostream>
#include "QueType.h"

using namespace std;

QueType :: QueType(){
    queueSize = 6;
    front = queueSize -1;
    rear = queueSize -1;
    items = new int[queueSize];
}

QueType :: QueType(int qSize){
    queueSize = qSize;
    front = queueSize -1;
    rear = queueSize -1;
    items = new int[queueSize];
}

QueType :: ~QueType(){
    delete [] items;
}

bool QueType :: isFull(){
    return ( (rear+1)%queueSize == front);
}

bool QueType :: isEmpty(){
    return (rear == front);
}

void QueType :: makeEmpty(){
    rear = queueSize - 1;
    front = rear;
}

void QueType :: Enqueue(int item){
    if(isFull()){
        throw FullQueue();
    }
    rear = (rear+1)%queueSize;
    items[rear] = item;
}

int QueType :: Dequeue(int& item){
    if(isEmpty()){
        throw EmptyQueue();
    }
    front = (front+1)%queueSize;
    item = items[front];
    return items[front];
}
