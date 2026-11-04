#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <string>
using namespace std;

struct dNode {
    int bookID;
    string title;
    dNode* left;
    dNode* right;

    dNode(int id, const string& name);
};

class DoublyLinkedList {
private:
    dNode* head;
    dNode* tail;
    dNode* current;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void InsertRight(dNode* node);
    void Next();
    void Previous();
    void PrintCurrent() const;
    void InsertAfterCurrent(dNode* node);
    dNode* RemoveCurrent();
    void PrintForward() const;
    void PrintBackward() const;
};

#endif
