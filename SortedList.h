#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

template <class T>

class SortedList{
public:
    SortedList();
    SortedList(int);
    void makeEmpty();
    bool isFull();
    int lengthIs();
    void resetList();
    void insertItem(T);
    T getNextItem();
    bool searchItem(T);
    void deleteItem(T);
private:
    int length;
    T* list;
    int currentPos;
    int capacity;

};

#endif // SORTEDLIST_H_INCLUDED
