#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED
#include "Heap.h"
class FullPQ{};
class EmptyPQ{};

class PQType{
public:
    PQType(int);
    ~PQType();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(int);
    void Dequeue(int&);
private:
    int length;
    Heap items;
    int maxItems;
};

#endif // PRIORITYQUEUE_H_INCLUDED
