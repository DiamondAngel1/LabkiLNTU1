#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Book {
public:
    string title;
    string author;
    double price;

    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    void PrintBookInfo() const {
        cout << "Назва: " << title
            << ", Автор: " << author
            << ", Ціна: " << price << " грн" << endl;
    }
};

class Bookstore {
private:
    vector<Book> books;

public:
    void AddBook(const Book& book) {
        books.push_back(book);
    }

    void PrintBooks() const {
        cout << "Список книг:" << endl;
        for (const Book& b : books) {
            b.PrintBookInfo();
        }
    }

    double CalculateTotalPrice() const {
        double total = 0;
        for (const Book& b : books) {
            total += b.price;
        }
        return total;
    }

    int СountBooks() const {
        return books.size();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Bookstore store;

    Book book1("Кобзар", "Тарас Шевченко", 355.0);
    Book book2("Волинь", "Улас Самчук", 377.0);
	Book book3("Марія", "Улас Самчук", 420.0);
    Book book4("Хіба ревуть воли як ясла повні", "Панас Мирний", 223.0);

    store.AddBook(book1);
    store.AddBook(book2);
    store.AddBook(book3);
	store.AddBook(book4);

    store.PrintBooks();

    cout << "Загальна вартість книг: "
        << store.CalculateTotalPrice() << " грн" << endl;

    cout << "Загальна кількість книг у магазині: "
        << store.СountBooks() << endl;

    return 0;
}
