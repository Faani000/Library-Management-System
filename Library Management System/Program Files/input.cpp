#include <iostream>
#include <limits>
#include <string>
#include "input.h"
using namespace std;

int ReadInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        if (cin.eof()) return -1;
        cout << "Invalid input. Please enter a whole number.\\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string ReadLine(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

void ReadBookDetails(int& id, string& title) {
    id = ReadInt("Enter Book ID: ");
    title = ReadLine("Enter Book Title: ");
}
