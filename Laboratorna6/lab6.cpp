#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	// Використання циклу while та логічні умови
    while (true) {
        double a, b, c;
        cout << "Введіть коефіцієнт a: ";
        cin >> a;
		// перевірка на коректність введення
        if (cin.fail()) {
			// якщо введено не число то очищуємо помилку і ігноруємо неправильний ввід
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Помилка: введено не число. Спробуйте ще раз" << endl;
            continue;
        }
        cout << "Введіть коефіцієнт b: ";
        cin >> b;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Помилка: введено не число. Спробуйте ще раз" << endl;
            continue;
        }
        cout << "Введіть коефіцієнт c: ";
        cin >> c;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Помилка: введено не число. Спробуйте ще раз" << endl;
            continue;
        }

        if (a == 0 && b == 0 && c == 0) {
            cout << "Усі коефіцієнти нулі. Рівняння має безліч розв'язків." << endl;
            break;
        }
        if (a == 0 && b == 0 && c != 0) { 
            cout << "Рівняння не має розв'язків (суперечність)." << endl; 
            break;
        }
        if (a == 0 && b != 0) {
            double x = -c / b;
            cout << "Це лінійне рівняння. Єдиний корінь: x = " << x << endl;
        }
        else {
            // Обчислення дискримінанта
            double d = b * b - 4 * a * c;
            cout << "Дискримінант d = " << d << endl;

            if (d < 0) {
                // якщо дискримінант менший за нуль, дійсних коренів немає
                cout << "Дійсних коренів немає. Спробуйте інші коефіцієнти" << endl;
                continue; // повторити введення
            }
            else if (d == 0) {
                // якщо дискримінант дорівнює нулю, єдиний корінь
                double x = -b / (2 * a);
                cout << "Єдиний корінь: x = " << x << endl;
            }
            else {
                // якщо дискримінант більший за нуль, два різних корені
                double x1 = (-b + sqrt(d)) / (2 * a);
                double x2 = (-b - sqrt(d)) / (2 * a);
                cout << "Два корені: x1 = " << x1 << ", x2 = " << x2 << endl;
            }
        }
        

        // Запит на завершення
        int exitChoice;
        while (true) {
            cout << "Вийти з програми? (1 - так, 0 - ні): ";
            cin >> exitChoice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Помилка: введено не число. Спробуйте ще раз." << endl;
                continue;
            }

            switch (exitChoice) {
                case 0:
                    break;
                case 1:
                    return 0;
                default:
                    cout << "Невірний вибір. Спробуйте ще раз." << endl;
                    continue; // повернутися на початок циклу
            }

            if (exitChoice == 0) {
                break;
            }
        }
    }
    
    
    // Я закоментувала цей блок коду, це той самий код тільки з використанням goto замість циклу while
	// goto це вже застарілий підхід і його не рекомендують використовувати в сучасному програмуванні через те що він дуже ускладнює читання коду
   /*
   start: // мітка для повторного введення так як while(true)
        double a, b, c; 
        cout << "введіть коефіцієнт a: ";
        cin >> a; 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "помилка: введено не число. спробуйте ще раз" << endl;
			goto start;// повертаємось до початку як у while(true) continue
        } 
        cout << "введіть коефіцієнт b: ";
        cin >> b; 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "помилка: введено не число. спробуйте ще раз" << endl;
            goto start;
        }
        cout << "введіть коефіцієнт c: ";
        cin >> c; 
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "помилка: введено не число. спробуйте ще раз" << endl; 
            goto start;
        }
        if (a == 0 && b == 0 && c == 0) {
            cout << "Усі коефіцієнти нулі. Рівняння має безліч розв'язків." << endl;
			return 0;
        }
        if (a == 0 && b == 0 && c != 0) {
            cout << "Рівняння не має розв'язків (суперечність)." << endl;
			return 0;
        }
        if (a == 0 && b != 0) {
            cout << "Це лінійне рівняння. Єдиний корінь: x = " << -c / b << endl;
	
        }
        else {
            double d = b * b - 4 * a * c;
            cout << "дискримінант d = " << d << endl;
            if (d < 0) {
                cout << "дійсних коренів немає. спробуйте інші коефіцієнти" << endl;
                goto start;
            }
            else if (d == 0) {
                double x = -b / (2 * a);
                cout << "єдиний корінь: x = " << x << endl;
            }
            else {
                double x1 = (-b + sqrt(d)) / (2 * a);
                double x2 = (-b - sqrt(d)) / (2 * a);
                cout << "два корені: x1 = " << x1 << ", x2 = " << x2 << endl;
            }
        }
    ask_exit:
        int exitchoice; 
        cout << "вийти з програми? (1 - так, 0 - ні): ";
        cin >> exitchoice;
        if (cin.fail()) { 
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "помилка: введено не число. спробуйте ще раз" << endl;
			goto ask_exit; // повертаємось на початок запиту на вихід
        }
        if (exitchoice == 1) { 
            return 0;
        } 
        else { 
			goto start; // повертаємось до початку для нового введення
        } 
        */
    return 0;
}