#include <iostream>
#include <string>
#include "doubly_linked_list.h"
#include "input.h"
#include "menu.h"
using namespace std;

int main() {
    DoublyLinkedList session;

    // Starter entries based on the Lab 07 example.
    session.InsertRight(new dNode(101, "Data Structures"));
    session.InsertRight(new dNode(102, "Database Systems"));
    session.InsertRight(new dNode(103, "Operating Systems"));

    cout << "Library Borrowing Session initialized.";
    session.PrintForward();

    bool running = true;
    while (running) {
        DisplayMenu();
        int choice = ReadInt("Enter your choice (1-9): ");

        switch (choice) {
        case 1:
            session.PrintCurrent();
            break;
        case 2:
            session.Next();
            session.PrintCurrent();
            break;
        case 3:
            session.Previous();
            session.PrintCurrent();
            break;
        case 4: {
            int id;
            string title;
            ReadBookDetails(id, title);
            if (title.empty()) {
                cout << "Title cannot be empty. Book was not added.\\n";
                break;
            }
            session.InsertRight(new dNode(id, title));
            cout << "Book inserted at the end.\\n";
            break;
        }
        case 5: {
            int id;
            string title;
            ReadBookDetails(id, title);
            if (title.empty()) {
                cout << "Title cannot be empty. Book was not added.\\n";
                break;
            }
            session.InsertAfterCurrent(new dNode(id, title));
            cout << "Book inserted after the current book.\\n";
            break;
        }
        case 6: {
            dNode* removed = session.RemoveCurrent();
            if (removed != nullptr) {
                cout << "Removed book: " << removed->bookID
                     << " - " << removed->title << endl;
                delete removed;
                cout << "Current pointer moved to the next book, "
                        "or previous book if no next book exists.\\n";
            } else {
                cout << "Nothing to remove; session is empty.\\n";
            }
            break;
        }
        case 7:
            session.PrintForward();
            break;
        case 8:
            session.PrintBackward();
            break;
        case 9:
            running = false;
            cout << "Exiting Library Borrowing Session.\\n";
            break;
        default:
            cout << "Invalid choice. Select a number from 1 to 9.\\n";
        }
    }

    return 0;
}
