#include <iostream>
#include "BinarySearchTree.h"
#include "PriorityQueue.h"
#include "QueType.h"
#include "Stack.h"
#include "Graph.h"

using namespace std;

void SelectionSort(int values[], int numValues);
void InsertionSort(int values[], int numValues);

int main()
{
    int array[] = {36,24,10,6,12};
    SelectionSort(array, 5);
    for(int i=0; i<5; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    int array2[] = {6,24,10,36,12};
    InsertionSort(array, 5);
    for(int i=0; i<5; i++){
        cout << array[i] << " ";
    }
    /*int array3 = {36,24,10,6,12};
    SelectionSort(array);*/
    return 0;
}

void Swapp(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
int FindMinIndex(int values[], int startIndex, int endIndex){
    int index = startIndex;
    for(int i=startIndex+1; i<=endIndex; i++){
        if(values[i] < values[index]){
            index = i;
        }
    }
    return index;
}
void SelectionSort(int values[], int numValues){
    int index;
    for(int c=0; c<numValues; c++){
        index = FindMinIndex(values, c, numValues-1);
        Swapp(values[c], values[index]);
    }
}
void Insert(int values[], int startIndex, int endIndex){
    bool finished = false;
    int current = endIndex;
    bool moretoSearch = (current != startIndex);
    while(moretoSearch && !finished){
        if(values[current] < values[current-1]){
            Swapp(values[current], values[current-1]);
            current--;
            moretoSearch = (current!=startIndex);
        }else{
            finished = true;
        }
    }
}
void InsertionSort(int values[], int numValues){
    for(int c=0; c<numValues; c++){
        Insert(values, 0, c);
    }
}
