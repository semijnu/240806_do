#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
    string title;
    int pages;

    Book(string title, int pages) {
        this->title = title;
        this->pages = pages;
    }
};

bool compare(Book a, Book b) {
    return a.pages < b.pages;
}

int main() {
    int numBooks;
    cout << "Enter number of books: ";
    cin >> numBooks;
    vector<Book> library;
    for (int i = 0; i < numBooks; i++) {
        string title;
        int pages;
        cout << "Enter book title: ";
        cin >> title;
        cout << "Enter number of pages: ";
        cin >> pages;
        Book book(title, pages);
        library.push_back(book);
    }
    sort(library.begin(), library.end(), compare);
    for (Book book : library) {
        cout << book.title << " " << book.pages << endl;
    }
    return 0;
}