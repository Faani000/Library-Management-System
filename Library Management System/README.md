# Library Management System — Doubly Linked List

A menu-driven C++ console program adapted from **Lab 07: Implementation of Doubly Linked List Class**. It manages the ordered list of books in a student's borrowing session.

## Features

1. Display the current book
2. Move to the next book
3. Move to the previous book
4. Insert a book at the end
5. Insert a book immediately after the current book
6. Remove the current book
7. Display the session from first to last
8. Display the session from last to first
9. Exit

The session starts with three example entries:
- 101 — Data Structures
- 102 — Database Systems
- 103 — Operating Systems

## Project structure

```text
library-borrowing-session/
├── Header Files/
│   ├── doubly_linked_list.h
│   ├── input.h
│   └── menu.h
├── Program Files/
│   ├── doubly_linked_list.cpp
│   ├── index.cpp
│   ├── input.cpp
│   └── menu.cpp
├── .gitignore
└── README.md
```

## Build and run

### Windows (PowerShell, MinGW g++)

Run these commands from the project root:

```powershell
$sources = Get-ChildItem -Path 'Program Files' -Filter *.cpp | ForEach-Object { $_.FullName }
g++ -std=c++11 -I 'Header Files' $sources -o library.exe
if ($LASTEXITCODE -eq 0) { .\\library.exe }
```

### Linux/macOS

```bash
g++ -std=c++11 -I "Header Files" "Program Files"/*.cpp -o library-borrowing-session
./library-borrowing-session
```

## Pointer design

Each `dNode` contains:
- `bookID` and `title`
- `left`: previous entry
- `right`: next entry

The list tracks `head`, `tail`, and `current`. The `Next()` and `Previous()` navigation operations take **O(1)** time. Insertion after the known current node and removal of the current node also take **O(1)** time.

When removing the current entry, its neighbors are connected directly. The current pointer moves to the next entry when available; otherwise it moves to the previous entry.

## Scope

This is a **borrowing-session list demonstration**, not a complete library circulation system. It does not implement borrowers, persistent storage, issue/return transactions, due dates, or fines.

## Lab alignment

The menu follows **Lab 07 Part A**. Part B asks students to identify a real bidirectional-traversal use case in their individual project; this repository implements Part A's library-session scenario.

## Notes

- Book entries are stored in memory only and are lost when the program exits.
- This project uses standard C++11 features and should compile with a compatible MinGW g++ compiler.


---


