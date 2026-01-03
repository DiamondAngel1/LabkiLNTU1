#include <iostream>
#define NOMINMAX
#include <algorithm>
#include <windows.h>
using namespace std;

// Функція для перетворення Цельсія у Фаренгейт
double celsiusToFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

// Функція для перетворення Фаренгейта у Цельсій
double fahrenheitToCelsius(double fahrenhait) {
    return (fahrenhait - 32.0) * 5.0 / 9.0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        // Оголошення змінних для градусів 
        double tempC, tempF;
        // Введення значень
        cout << "Введіть температуру у градусах Цельсія: ";
        cin >> tempC;
        cout << "Введіть температуру у градусах Фаренгейта: ";
        cin >> tempF;

        // Перетворення використовуючи функції
        double convToF = celsiusToFahrenheit(tempC);
        double convToC = fahrenheitToCelsius(tempF);

        // Виведення результатів
        cout << tempC << " C = " << convToF << " F" << endl;
        cout << tempF << " F = " << convToC << " C" << endl;

        // Обчислення суми та середнього
        double sum = convToF + convToC;
        double average = sum / 2.0;
        double minimum = min(tempC, tempF);
        double maximum = max(tempC, tempF);
        double minimumAll = min({tempC, tempF, convToC, convToF});
		double maximumAll = max({ tempC, tempF, convToC, convToF });
		bool biggerTemp = convToC > tempC;
		

        // Вивід результатів
        cout << "Сума результатів = " << sum << endl;
        cout << "Середнє значення = " << average << endl;
        cout << "Мінімальне введене значення = " << minimum << endl;
        cout << "Максимальне введене значення = " << maximum << endl;
		cout << "Мінімальне значення серед усіх = " << minimumAll << endl;
		cout << "Максимальне значення серед усіх = " << maximumAll << endl;
        if (biggerTemp) {
			cout << "Температура введена в Фаренгейтах більша за введену в Цельсіях" << endl << endl;
		}
		else {
			cout << "Температура введена в Цельсіях більша за введену в Фаренгейтах" << endl << endl;
        }

        int exitChoice;
        cout << "Вийти з програми? (1-так (завершити), 0-ні (продовжити)): ";
        cin >> exitChoice;
        if (exitChoice == 1) {
            break;
        }
    }
    
    return 0;
}
