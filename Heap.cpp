#include <iostream>
#include "Heap.h"

using namespace std;

Heap :: Heap(){
    numElements = 0;
}

void Swap(int&a ,int& b){
    int temp = a;
    a = b;
    b = temp;
}
void Heap :: ReheapUp(int root, int bottom){
    if(bottom > root){
        int parent = (bottom-1)/2;
        if(elements[parent] < elements[bottom]){
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}

void Heap :: ReheapDown(int root, int bottom){
    int maxChild;
    int leftChild = (root*2)+1;
    int rightChild = (root*2)+2;
    if(leftChild <= bottom){
        if(leftChild == bottom){
            maxChild = leftChild;
        }else{
            if(elements[leftChild] < elements[rightChild]){
                maxChild = rightChild;
            }else{
                maxChild = leftChild;
            }
        }
    }
    if(elements[root] < elements[maxChild]){
        Swap(elements[root], elements[maxChild]);
        ReheapDown(maxChild, bottom);
    }
}
