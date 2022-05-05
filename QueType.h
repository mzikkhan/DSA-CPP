#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED

class EmptyQueue{};
class FullQueue{};

class QueType{
public:
    QueType();
    QueType(int);
    ~QueType();
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    void Enqueue(int);
    int Dequeue(int&);
private:
    int front;
    int rear;
    int queueSize;
    int *items;
};

#endif // QUETYPE_H_INCLUDED
