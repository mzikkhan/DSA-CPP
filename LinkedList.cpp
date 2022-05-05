#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList :: LinkedList(){
    cout << "OK";
    head = NULL;
}

LinkedList :: LinkedList(int n){
    cout << "OK";
    head = NULL;
}

void LinkedList :: deleteFirstNode(){
    if(head == NULL){
        return;
    }
    Node* temp;
    temp = head;
    head = head->next;
    delete temp;
}

void LinkedList :: deleteLastNode(){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteFirstNode();
    }
    Node* current;
    current = head;
    while(current->next ->next != NULL){
        current = current->next;
    }
    Node* temp = current-> next;
    current -> next = NULL;
    delete temp;
}

void LinkedList :: addNodeFront(int data){
    Node* newNode;
    newNode->info = data;
    newNode->next = head;
    head = newNode;
}


void LinkedList :: addNodeBack(int data){
    Node* newNode;
    newNode->info = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList :: printNodes(){
    Node* current = head;
    cout << "head -> ";
    while(current != NULL){
        cout << current-> info << " -> ";
        current = current->next;
    }
    cout << endl;
}
