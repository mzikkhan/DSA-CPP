#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class LinkedList{

    struct Node{
        int info;
        Node* next;
    };
    private:
        Node* head;
    public:
        LinkedList();
        LinkedList(int);
        void deleteFirstNode();
        void deleteLastNode();
        void addNodeFront(int);
        void addNodeBack(int);
        void printNodes();
};

#endif // LINKEDLIST_H_INCLUDED
