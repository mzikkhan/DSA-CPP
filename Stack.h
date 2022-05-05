#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

class FullStack{};
class EmptyStack{};

class Stack{
public:
    Stack();
    Stack(int);
    ~Stack();
    void makeEmpty();
    bool isFull();
    bool isEmpty();
    void push(int);
    void pop(int&);
    int top();
private:
    int stackSize;
    int topIndex;
    int *items;
};

#endif // STACK_H_INCLUDED
