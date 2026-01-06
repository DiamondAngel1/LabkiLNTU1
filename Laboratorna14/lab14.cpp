#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    string text = "Hello, my name is Petro";
    cout << "Початковий рядок: " << text << endl;

    // find() повертає позицію першого входження підрядка або string::npos, якщо не знайдено
	// string::npos - це спеціальне значення, яке вказує на те, що підрядок не знайдено
    string findstr = "is Petro";
    size_t pos = text.find(findstr);

    if (pos != string::npos) {
        cout << "Підрядок \"" << findstr << "\" знайдено на позиції: " << pos << endl;
        // replace(позиція, довжина замінюваного тексту, новий текст)
        text.replace(pos, findstr.length(), "isn't Maria");
        cout << "Після заміни підрядка: " << text << endl;

    }
    else {
        cout << "Підрядок \"" << findstr << "\" не знайдено." << endl;
		cout << "Рядок залишається без змін: " << text << endl;
    }

    // rfind(підрядок, позиція) == 0 означає, що підрядок знайдено на початку
    string start = "Hello";
    if (text.rfind(start, 0) == 0) {
        cout << "Рядок починається з \"" << start << "\"" << endl;
    }
    else {
        cout << "Рядок НЕ починається з \"" << start << "\"" << endl;
    }

    // compare(позиція початку, довжина, підрядок) == 0 - збігається
    string end = "Petro";
    if (text.size() >= end.size() &&
        text.compare(text.size() - end.size(), end.size(), end) == 0) {
        cout << "Рядок закінчується на \"" << end << "\"" << endl;
    }
    else {
        cout << "Рядок НЕ закінчується на \"" << end << "\"" << endl;
    }

    // erase(позиція, кількість_символів)
    text.erase(0, 6);
    cout << "Після видалення частини рядка: " << text << endl;

    return 0;
}
