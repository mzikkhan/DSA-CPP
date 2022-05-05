#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

class Heap{
public:
    Heap();
    void ReheapUp(int,int);
    void ReheapDown(int,int);
    int* elements;
private:
    int numElements;
};

#endif // HEAP_H_INCLUDED
