#pragma once

#include "Book.h"
#include <vector>
#include "CheckInOrOutResult.h"

class Inventory
{

private:
    std::vector<Book> Books;
    int MaxBookId;

public:


    Inventory();

    void DisplayAllBooks();
    void DisplayCheckoutBooks();

    int GetNextBookId();
    int NumberOfBooks();

    Book GetBookByIndex(int index);
    void AddBook(Book Book);
    void RemoveBook(std::string title);

    int FindBookByTitle(std::string title);
    CheckInOrOutResult CheckInOrOutBook(std::string title, bool checkOut);
};