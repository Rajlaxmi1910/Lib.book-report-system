#ifndef BOOK_PROCESSING_H
#define BOOK_PROCESSING_H
struct Book {
    int id;
    char name[100];
    char writer[100];
    float cost;
};
void addBook();
void viewBooks();
void searchBook();
void updateBook();
void deleteBook();

#endif
