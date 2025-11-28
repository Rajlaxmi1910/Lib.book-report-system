Description

This project is a simple C-based Library Management System that allows users to store and manage book records using a binary file (books.dat). It supports adding, viewing, searching, updating, and deleting book records through a menu‑driven console interface.
Each book contains:
ID (integer)
Name (string)
Writer (string)
Cost (float)

Repository Structure
       ...   library-management/
          ├── src/
          │ └── main.c
          ├── assets/
          │ ├── sample_output1.png
          │ ├── sample_output2.png
          │ └── sample_output3.png
          ├── docs/
          |  ├── Algorithm.txt
          │ ├── Flowchart.txt
          │ └── ProjectReport.pdf
        ...  └── README.md

Requirements

A C compiler (GCC recommended)
Any text editor (VS Code, Notepad++, Notepad, etc.)

Build Instructions

Clone or download the project
Navigate to the src/ directory
Compile the program
Run the program

Usage

When you run the program, the following menu appears:
1. Add Book
Prompts for ID, name, writer, and cost, then saves the book to books.dat.
2. View Books
Displays all stored book records.
3. Search Book
Search for a book by entering its ID.
4. Update Book
Modifies an existing book's details using its ID.
5. Delete Book
Deletes a book by copying all others into a temporary file.
6. Exit
Closes the program.
