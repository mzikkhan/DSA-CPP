#include <iostream>
#include "PriorityQueue.h"

using namespace std;

PQType :: PQType(int max){
    maxItems = max;
    items.elements = new int[max];
    length = 0;
}
PQType :: ~PQType(){
    delete [] items.elements;
}
void PQType :: MakeEmpty(){
    length = 0;
}
bool PQType :: IsFull(){
    return (length == maxItems);
}
bool PQType :: IsEmpty(){
    return (length == 0);
}
void PQType :: Enqueue(int item){
    if(IsFull()){
        throw FullPQ();
    }else{
        length++;
        items.elements[length-1] = item;
        items.ReheapUp(0, length-1);
    }
}
void PQType :: Dequeue(int& item){
    if(IsEmpty()){
        throw EmptyPQ();
    }else{
        item = items.elements[0];
        items.elements[0] = items.elements[length-1];
        length--;
        items.ReheapDown(0, length-1);
    }
}
