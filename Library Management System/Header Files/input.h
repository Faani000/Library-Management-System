#ifndef INPUT_H
#define INPUT_H

#include <string>
using namespace std;

int ReadInt(const string& prompt);
string ReadLine(const string& prompt);
void ReadBookDetails(int& id, string& title);

#endif
