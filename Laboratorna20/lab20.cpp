#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

bool isInteger(const string& s) { // Функція для перевірки, чи рядок є цілим числом
    if (s.empty()) {
        return false;
    }
    char* end;
	long val = strtol(s.c_str(), &end, 10); // strtol конвертує рядок у long, c_str() повертає вказівник на C-рядок, &end вказує на позицію першого неконвертованого символу, 10 - основа системи числення
	return (*end == '\0'); // перевіряємо, чи всі символи були конвертовані. '\0' означає кінець рядка
}

bool isDouble(const string& s) { // Функція для перевірки, чи рядок є дробовим числом
    if (s.empty()) {
        return false;
    }
    char* end;
	double val = strtod(s.c_str(), &end); // strtod конвертує рядок у double
    return (*end == '\0');
}

void writeCSV(const vector<vector<string>>& table, const string& filename) { // Функція для запису таблиці у CSV файл
	ofstream fout(filename); // відкриваємо файл для запису
    if (!fout.is_open()) {
        cout << "Не вдалося створити файл!" << endl;
        return;
    }
    for (const auto& row : table) {
		for (size_t j = 0; j < row.size(); j++) { // ітеруємо по кожному елементу рядка для запису у файл. Використовується size_t для уникнення проблем з від'ємними індексами 
            fout << row[j];
            if (j < row.size() - 1) fout << ",";
        }
        fout << "\n";
    }
	fout.close(); // закриваємо файл
    cout << "Файл " << filename << " успішно створено!" << endl;
}

void searchAndReplace(vector<vector<string>>& table, const string& searchValue, const string& replaceValue) { // Функція для пошуку та заміни значень у таблиці
	for (auto& row : table) { // ітеруємо по кожному рядку таблиці. Тип auto дозволяє компілятору автоматично визначити тип змінної row для зручності
        for (auto& cell : row) {
            if (cell == searchValue) {
                cell = replaceValue;
            }
        }
    }
}

int main() {
    int rows, cols;
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

	vector<vector<string>> table(rows, vector<string>(cols, "")); // 2D вектор для зберігання таблиці рядків

    char choice;
    do {
        int r, c;
        cout << "Введіть номер рядка (0.." << rows - 1 << "): ";
        cin >> r;
        cout << "Введіть номер стовпця (0.." << cols - 1 << "): ";
        cin >> c;

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Некоректні координати!" << endl;
            continue;
        }

        cout << "Оберіть тип даних (i - ціле, d - дробове, s - текст): ";
        char type;
        cin >> type;

        cout << "Введіть значення: ";
        string value;
        // очищуємо буфер вводу перед getline щоб уникнути пропуску вводу рядка. Використовується numeric_limits для ігнорування всіх символів до
        // кінця рядка, streamsize - максимальний розмір потоку
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, value);

        bool valid = false;
        switch (type) {
            case 'i': 
                valid = isInteger(value); 
                break;
            case 'd': 
                valid = isDouble(value);
                break;
            case 's': 
                valid = true;
                break;
            default: 
                cout << "Невідомий тип" << endl;
        }

		if (valid) { // якщо значення відповідає обраному типу, зберігаємо його у таблиці
            table[r][c] = value;
            cout << "Значення збережено" << endl;
        }
        else {
            cout << "Помилка: значення не відповідає обраному типу" << endl;
        }

        cout << "Бажаєте ввести ще одне значення? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "Введіть значення для пошуку: ";
    string searchVal;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, searchVal);

    cout << "Введіть значення для заміни: ";
    string replaceVal;
    getline(cin, replaceVal);

    searchAndReplace(table, searchVal, replaceVal);

	writeCSV(table, "output.csv"); // Записуємо таблицю у CSV файл

    return 0;
}
