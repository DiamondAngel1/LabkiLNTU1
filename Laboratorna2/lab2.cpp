#include <iostream>
#include <algorithm>
#define NOMINMAX
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Оголошення змінних різних типів
    int age, a, b, c;
    double price;
    char letter;
    string name;

    // Присвоєння значень змінним
    age = 17;
    a = 4;
    b = 22;
    c = 35;
    price = 76.99;
    letter = 'A';
    name = "Сюзанна";

    // Виведення значень змінних на екран
    cout << "Значення змінної age: " << age << endl;
    cout << "Значення змінної price: " << price << endl;
    cout << "Значення змінної letter: " << letter << endl;
    cout << "Значення змінної name: " << name << endl;

    // Обчислення суми, середнього, мінімуму та максимуму
    int sum = age + a + b + c;
    double average = sum / 4.0;
    int minimum = min({ age, a, b, c });
    int maximum = max({ age, a, b, c });

    // Виведення результатів обчислень
    cout << "Значення змінних: " << age << ", " << a << ", " << b << ", " << c << endl;
    cout << "Сума: " << sum << endl;
    cout << "Середнє: " << average << endl;
    cout << "Мінімум: " << minimum << endl;
    cout << "Максимум: " << maximum << endl;

    return 0;
}