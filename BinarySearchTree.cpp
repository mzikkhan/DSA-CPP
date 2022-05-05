#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree :: BinarySearchTree(){
    root = NULL;
}

bool BinarySearchTree :: IsEmpty(){
    return (root == NULL);
}

bool BinarySearchTree :: IsFull(){
    Node* temp;
    try{
        temp = new Node;
        delete temp;
        return false;
    }catch(std::bad_alloc exception){
        return true;
    }
}

void BinarySearchTree :: MakeEmpty(){
    root = NULL;
}

//Finding length of tree
int CountNodes(Node* tree){
    if(tree==NULL){
        return 0;
    }
    return 1 + CountNodes(tree->left) + CountNodes(tree->right);
}
int BinarySearchTree :: LengthIs(){
    return CountNodes(root);
}

//Inserting item into tree
void Insert(Node*& tree, int item){
    if(tree==NULL){
        tree = new Node;
        tree->left = NULL;
        tree->right = NULL;
        tree->info = item;
    }else if(item < tree->info){
        Insert(tree->left, item);
    }else{
        Insert(tree->right, item);
    }
}
void BinarySearchTree :: InsertItem(int item){
    Insert(root, item);
}

//Delete an item from the tree
void GetPredecessorNode(Node* tree, int& data){
    while(tree->right != NULL){
        tree = tree->right;
    }
    data = tree->info;
}
void Delete(Node*& tree,int item);
void DeleteNode(Node*& tree, int item){
    int data;
    Node* temp = tree;
    if(tree->right == NULL && tree->left == NULL){
        tree=NULL;
        delete temp;
    }else if(tree->right == NULL){
        tree = tree->left;
        delete temp;
    }else if(tree->left == NULL){
        tree = tree->right;
        delete temp;
    }else{
        GetPredecessorNode(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}
void Delete(Node*& tree,int item){
    if(item < tree->info){
        Delete(tree->left, item);
    }else if(item > tree->info){
        Delete(tree->right, item);
    }else{
        DeleteNode(tree, item);
    }
}
void BinarySearchTree :: DeleteItem(int item){
    Delete(root, item);
}

//Printing the items in order
void PrintTree(Node*& tree){
    if(tree!=NULL){
        PrintTree(tree->left);
        cout << tree->info << " ";
        PrintTree(tree->right);
    }
}
void BinarySearchTree :: Print(){
    PrintTree(root);
}

//Retrieving an item
void Retrieve(Node* tree, int& item, bool& found){
    if(tree==NULL){
        return;
    }else if(item < tree->info){
        Retrieve(tree->left, item, found);
    }else if(item > tree->info){
        Retrieve(tree->right, item , found);
    }else{
        item = tree->info;
        found = true;
    }
}
void BinarySearchTree :: RetrieveItem(int& item, bool& found){
    found = false;
    Retrieve(root, item, found);
}

//Resetting the tree
void InOrder(Node* tree, QueType& inQue){
    if(tree!=NULL){
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}
void PreOrder(Node* tree, QueType& preQue){
    if(tree!=NULL){
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}
void PostOrder(Node* tree, QueType& postQue){
    if(tree!=NULL){
        postQue.Enqueue(tree->info);
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
    }
}
void BinarySearchTree :: ResetTree(OrderType order){
    switch(order){
        case PRE_ORDER:
            PreOrder(root, preQue);
            break;
        case POST_ORDER:
            PostOrder(root, postQue);
            break;
        case IN_ORDER:
            InOrder(root, inQue);
            break;
    }
}

//Getting next item in list


int BinarySearchTree :: GetNextItem(OrderType order, bool& finished){
    finished = false;
    int item;
    switch(order){
        case PRE_ORDER:
            preQue.Dequeue(item);
            if(preQue.isEmpty()){
                finished = true;
            }
            break;
        case IN_ORDER:
            inQue.Dequeue(item);
            if(inQue.isEmpty()){
                finished = true;
            }
            break;
        case POST_ORDER:
            postQue.Dequeue(item);
            if(postQue.isEmpty()){
                finished = true;
            }
            break;
    }
    return item;
}


//
