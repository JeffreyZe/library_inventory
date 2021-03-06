#include "../include/Inventory.h"
#include <vector>

// int Inventory::GetNextBookId()
// {
//     Inventory::MaxBookId++;
//     return Inventory::MaxBookId;
// }

int Inventory::NumberOfBooks()
{
    return Inventory::Books.size();
}

void Inventory::AddBook(Book book)
{
    // Inventory::MaxBookId++;
    Book lastBoook = Books.back();

    book.Id = lastBoook.Id + 1;

    Inventory::Books.push_back(book);
}

Book Inventory::GetBookByIndex(int index)
{
    return Inventory::Books[index];
}

void Inventory::RemoveBook(std::string title)
{
    //TODO: handle maxBookId when removing

    std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));

    if (it != Inventory::Books.end())
    {
        Inventory::Books.erase(it);
    }
}

int Inventory::FindBookByTitle(std::string title)
{

    std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));

    if (it == Inventory::Books.end())
    {
        return -1;
    }

    int index = it - Inventory::Books.begin();

    return index;
}

CheckInOrOutResult Inventory::CheckInOrOutBook(std::string title, bool checkOut)
{
    int foundBookIndex = FindBookByTitle(title);

    if (foundBookIndex < 0)
    {
        return CheckInOrOutResult::BookNotFound;
    }
    else if (checkOut == Books[foundBookIndex].IsCheckedOut())
    {
        if (checkOut)
        {
            return CheckInOrOutResult::AlreadyCheckedOut;
        }
        else
        {
            return CheckInOrOutResult::AlreadyCheckedIn;
        }
    }
    else
    {
        Books[foundBookIndex].CheckInOrOut(checkOut);
        return CheckInOrOutResult::Success;
    }
}

void Inventory::DisplayAllBooks()
{
    std::cout << "\nID\tTitle\tAuthor" << std::endl;
    for (int i = 0; i < NumberOfBooks(); i++)
    {
        Books[i].DisplayBook();
    }
    std::cout << std::endl;
}

void Inventory::DisplayCheckoutBooks()
{
    std::cout << "\nID\tTitle\tAuthor" << std::endl;
    for (int i = 0; i < NumberOfBooks(); i++)
    {
        if (GetBookByIndex(i).IsCheckedOut())
        {
            Books[i].DisplayBook();
        }
    }
    std::cout << std::endl;
}