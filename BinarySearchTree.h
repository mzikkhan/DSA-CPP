#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

struct Node{
    int info;
    Node* left;
    Node* right;
};

class BinarySearchTree{
public:
    BinarySearchTree();
    bool IsEmpty();
    bool IsFull();
    void MakeEmpty();
    int LengthIs();
    void InsertItem(int);
    void DeleteItem(int);
    void Print();
    void RetrieveItem(int&, bool&);
    void ResetTree(OrderType);
    int GetNextItem(OrderType, bool&);
private:
    Node* root;
    QueType preQue;
    QueType inQue;
    QueType postQue;
};

#endif // BINARYSEARCHTREE_H_INCLUDED
