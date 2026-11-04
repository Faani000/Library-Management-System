#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

dNode::dNode(int id, const string& name) {
    bookID = id;
    title = name;
    left = nullptr;
    right = nullptr;
}

DoublyLinkedList::DoublyLinkedList() {
    head = tail = current = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    dNode* node = head;
    while (node != nullptr) {
        dNode* nextNode = node->right;
        delete node;
        node = nextNode;
    }
}

void DoublyLinkedList::InsertRight(dNode* node) {
    if (node == nullptr) return;

    node->left = tail;
    node->right = nullptr;

    if (tail != nullptr)
        tail->right = node;
    else
        head = node;

    tail = node;
    if (current == nullptr) current = node;
}

void DoublyLinkedList::Next() {
    if (current != nullptr && current->right != nullptr)
        current = current->right;
    else
        cout << "No next book.\\n";
}

void DoublyLinkedList::Previous() {
    if (current != nullptr && current->left != nullptr)
        current = current->left;
    else
        cout << "No previous book.\\n";
}

void DoublyLinkedList::PrintCurrent() const {
    if (current == nullptr) {
        cout << "The borrowing session is empty.\\n";
        return;
    }
    cout << "Current Book: " << current->bookID << " - "
         << current->title << endl;
}

void DoublyLinkedList::InsertAfterCurrent(dNode* node) {
    if (node == nullptr) return;

    if (current == nullptr) {
        InsertRight(node);
        return;
    }

    node->left = current;
    node->right = current->right;

    if (current->right != nullptr)
        current->right->left = node;
    else
        tail = node;

    current->right = node;
}

dNode* DoublyLinkedList::RemoveCurrent() {
    if (current == nullptr) return nullptr;

    dNode* removed = current;
    dNode* previous = current->left;
    dNode* nextNode = current->right;

    if (previous != nullptr)
        previous->right = nextNode;
    else
        head = nextNode;

    if (nextNode != nullptr)
        nextNode->left = previous;
    else
        tail = previous;

    current = (nextNode != nullptr) ? nextNode : previous;
    removed->left = nullptr;
    removed->right = nullptr;
    return removed;
}

void DoublyLinkedList::PrintForward() const {
    cout << "\\nBorrowing Session (Forward):\\n";
    if (head == nullptr) {
        cout << "Session is empty.\\n";
        return;
    }

    for (dNode* node = head; node != nullptr; node = node->right) {
        cout << node->bookID << " - " << node->title;
        if (node == current) cout << " [CURRENT]";
        cout << endl;
    }
}

void DoublyLinkedList::PrintBackward() const {
    cout << "\\nBorrowing Session (Backward):\\n";
    if (tail == nullptr) {
        cout << "Session is empty.\\n";
        return;
    }

    for (dNode* node = tail; node != nullptr; node = node->left) {
        cout << node->bookID << " - " << node->title;
        if (node == current) cout << " [CURRENT]";
        cout << endl;
    }
}
