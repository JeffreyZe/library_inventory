#include <iostream>
#include "../include/Book.h"
#include "../include/Inventory.h"
#include <string>

using namespace std;

Inventory _inventory;

void DisplayMainMenu()
{
    cout << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Add book" << endl;
    cout << "2. List all books" << endl;
    cout << "3. Check out book" << endl;
    cout << "4. Check in book" << endl;
    cout << "5. Remove book from library" << endl;
    cout << "6. List all checked out books" << endl;

    cout << "0. Exit:" << endl;
}

void AddNewBook()
{
    cout << "Title: ";
    string title;
    getline(cin, title);

    cout << "Author: ";
    string author;
    getline(cin, author);

    Book newBook(title, author);

    _inventory.AddBook(newBook);
}

void ListAllBooks()
{

    _inventory.DisplayAllBooks();
}

void CheckInOrOutBook(bool CheckOut)
{
    string inOrOut;
    if (CheckOut)
    {
        inOrOut = "out";
    }
    else
    {
        inOrOut = "in";
    }

    cout << "Enter a book title to check " + inOrOut + ": ";
    string title;
    getline(cin, title);

    CheckInOrOutResult result = _inventory.CheckInOrOutBook(title, CheckOut);

    if (result == CheckInOrOutResult::BookNotFound)
    {
        cout << "Book not found" << endl;
    }
    else if (result == CheckInOrOutResult::Success)
    {
        cout << "Book checked " << inOrOut << "!" << endl;
    }
    else if (result == CheckInOrOutResult::AlreadyCheckedOut || result == CheckInOrOutResult::AlreadyCheckedIn)
    {
        cout << "Book already checked " + inOrOut << endl;
    }
    else
    {
        cout << "Book failed checking " << inOrOut << "!" << endl;
    }

    // refactored the following code
    // int foundBookIndex = _inventory.FindBookByTitle(title);

    // if (foundBookIndex >= 0)
    // {
    //     Book* foundBook = _inventory.GetBookByIndex(foundBookIndex);

    //     if (foundBook->CheckedOut == CheckOut)
    //     {
    //         cout << "Book already checked " + inOrOut << endl;
    //         return;
    //     }

    //     if (CheckOut)
    //     {
    //         _inventory.CheckOutBook(foundBook);
    //     }
    //     else
    //     {
    //         _inventory.CheckInBook(foundBook);
    //     }

    //     cout << "Book checked " + inOrOut << endl;
    // }
    // else
    // {
    //     cout << "Book not found" << endl;
    // }
}

void RemoveBook()
{
    cout << "Title: ";
    string title;
    getline(cin, title);

    _inventory.RemoveBook(title);
    cout << "Book <" << title << "> removed" << endl;
    return;
}

void ListCheckoutBooks()
{

    _inventory.DisplayCheckoutBooks();
}

int main()
{

    // Book myBook(1, "Harry Potter", "J.K R");
    // std::cout << myBook.Title << std::endl;

    while (true)
    {
        DisplayMainMenu();

        int input;
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 0:
            cout << "Thank you. Goodbye" << endl;
            return 0;
        case 1:
            AddNewBook();
            break;
        case 2:
            ListAllBooks();
            break;
        case 3:
            // CheckOutBook();
            CheckInOrOutBook(true);
            break;

        case 4:
            // CheckInBook();
            CheckInOrOutBook(false);
            break;
        case 5:
            RemoveBook();
            break;

        case 6:
            ListCheckoutBooks();
            break;

        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }
    }
}