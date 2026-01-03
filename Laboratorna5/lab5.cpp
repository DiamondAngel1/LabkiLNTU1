#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	//оголошення змінної для балансу
	double balance = 0;
	while (true) {
		//Цикл для вибору операції
		cout << "Оберіть тип операції: " << endl;
		cout << "1 - Переглянути баланс" << endl;
		cout << "2 - Внести кошти" << endl;
		cout << "3 - Зняття коштів" << endl;
		cout << "4 - Вийти" << endl;
		int choice;
		cin >> choice;
		// Обробка вибору користувача
		switch (choice) {
		case 1:
			// Вивід балансу
			cout << "Ваш баланс: " << balance << " грн." << endl << endl;
			break;
		case 2:
			double deposit;
			cout << "Введіть суму для внесення: ";
			cin >> deposit;
			// Перевірка на додатність суми внесення
			if (deposit <= 0) {
				cout << "Сума внесення має бути більшою за 0" << endl << endl;
				break;
			}
			else {
				balance += deposit;
				cout << "Ви внесли: " << deposit << endl << endl;
			}
			break;
		case 3:
			double withdraw;
			cout << "Введіть суму для зняття: ";
			cin >> withdraw;
			// Перевірка чи достатньо коштів на балансі та мінімального залишку
			if (withdraw > balance) {
				cout << "Недостатньо коштів на балансі" << endl << endl;
			}
			else if (balance - withdraw < 50) {
				cout << "Після зняття на балансі має залишатися не менше 50 грн" << endl << endl;
			}
			else {
				balance -= withdraw;
				cout << "Ви зняли: " << withdraw << endl << endl;
			}
			break;
		case 4:
			// Вихід з програми
			cout << "Вихід з програми" << endl;
			return 0;
		default:
			// Обробка некоректного вибору
			cout << "Ви обрали не існуючий варіант. Спробуйте ще раз" << endl << endl;
			continue;
		}
	}
    return 0;
}
