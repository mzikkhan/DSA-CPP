#ifndef UNSORTEDLIST_H_INCLUDED
#define UNSORTEDLIST_H_INCLUDED

template <class T>

class UnsortedList{
public:
    UnsortedList();
    UnsortedList(int);
    void makeEmpty();
    bool isFull();
    int lengthIs();
    void resetList();
    void insertItem(T);
    T getNextItem();
    void searchItem(T&, bool&);
    void deleteItem(T);
private:
    int length;
    T* list;
    int currentPos;
    int capacity;

};
#endif // UNSORTEDLIST_H_INCLUDED
