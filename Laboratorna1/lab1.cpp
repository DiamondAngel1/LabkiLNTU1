#include<iostream>
#include<cmath>
#include <cctype>
#include<Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Демонстрація роботи з різними типами даних
	cout << "=======Оголошення змінних різних типів та виконання над ними операцій присвоювання=======" << endl;
	// оголошення змінної типу int
	int number = 38;
	cout << "Початкове число типу int: " << number << endl;
	number += 2;
	cout << "Число після додавання 2: " << number << endl;
	number *= 2;
	cout << "Число після множення на 2: " << number << endl;
	number -= 2;
	cout << "Число після віднімання 2: " << number << endl;
	number /= 2;
	cout << "Число після ділення на 2: " << number << endl;
	number %= 2;
	cout << "Число після ділення без остачі на 2: " << number << endl << endl;

	// оголошення змінної типу long
	long seconds = 390000;
	cout << "Число типу long: " << seconds << endl;
	seconds -= 10000;
	cout << "Число після віднімання 10000: " << seconds << endl;
	seconds += 5000;
	cout << "Число після додавання 5000: " << seconds << endl;
	seconds *= 2;
	cout << "Число після множення на 2: " << seconds << endl;
	seconds /= 4;
	cout << "Число після ділення на 4: " << seconds << endl;
	seconds %= 7;
	cout << "Число після ділення без остачі на 7: " << seconds << endl << endl;

	// оголошення змінної типу short
	short hours = 13;
	cout << "Число типу short: " << hours << endl;
	hours += 5;
	cout << "Число після додавання 5: " << hours << endl;
	hours -= 3;
	cout << "Число після віднімання 3: " << hours << endl;
	hours *= 2;
	cout << "Число після множення на 2: " << hours << endl;
	hours /= 4;
	cout << "Число після ділення на 4: " << hours << endl;
	hours %= 3;
	cout << "Число після ділення без остачі на 3: " << hours << endl << endl;

	// оголошення змінної типу float
	float pi = 3.14f;
	cout << "Початкове значення float: " << pi << endl;
	pi /= 2;
	cout << "Число після ділення на 2: " << pi << endl;
	pi *= 4;
	cout << "Число після множення на 4: " << pi << endl;
	pi -= 1.14f;
	cout << "Число після віднімання 1.14: " << pi << endl;
	pi += 2.0f;
	cout << "Число після додавання 2.0: " << pi << endl << endl;

	// оголошення змінної типу double
	double price = 67.99;
	cout << "Початкове число типу double: " << price << endl;
	price += 10.01;
	cout << "Число після додавання 10.01: " << price << endl;
	price *= 2;
	cout << "Число після множення на 2: " << price << endl;
	price -= 5.50;
	cout << "Число після віднімання 5.50: " << price << endl;
	price /= 3;
	cout << "Число після ділення на 3: " << price << endl << endl;

	// оголошення змінної типу string
	string name = "Сюзанна";
	cout << "Початкове значення рядка string: " << name << endl;
	name += " Тарарук";
	cout << "Рядок після додавання: " << name << endl << endl;

	// оголошення змінної типу char
	char letter = 'A';
	cout << "Початкове значення символу char: " << letter << endl;
	letter = 'B';
	cout << "Зміна символу: " << letter << endl;
	letter += 2;
	cout << "Зміна символу з додаванням 2: " << letter << endl;
	letter -= 1;
	cout << "Зміна символу з відніманням 1: " << letter << endl << endl;

	// оголошення змінної типу bool
	bool isMan = true;
	cout << "Початкове значення bool: " << isMan << endl;
	// зміна булевого типу
	isMan = false;
	cout << "Зміна бульового типу: " << isMan << endl << endl;

	cout << "=======Приклади роботи з стандартними математичними функціями=======" << endl;
	// приклади роботи з математичними функціями 
	double value = -10.6;
	cout << "Початкове число: " << value << endl;
	cout << "Квадратний корінь 25 (sqrt): " << sqrt(25) << endl;
	cout << "Степінь числа в 3 (pow): " << pow(value, 2) << endl;
	cout << "Абсолютне значення (abs): " << abs(value) << endl;
	cout << "Округлення вгору (ceil): " << ceil(value) << endl;
	cout << "Округлення вниз (floor): " << floor(value) << endl << endl;

	cout << "=======Приклади роботи з стандартними функціями для рядків=======" << endl;
	// приклади роботи з рядками 
	string text = "Hello World";
	cout << "Рядок: " << text << endl;
	cout << "Довжина рядка (length): " << text.length() << endl;
	cout << "Підрядок (substr): " << text.substr(0, 5) << endl;
	cout << "Пошук слова 'World' (find): " << text.find("World") << endl;

	// перетворення символів у верхній та нижній регістр
	char c = 'd';
	cout << "Початковий символ: " << c << endl;
	cout << "Верхній регістр (toupper): " << (char)toupper(c) << endl;
	cout << "Нижній регістр (tolower): " << (char)tolower(c) << endl;

	cout << "=======6.Варіант оператори присвоєння=======" << endl;
	// робота з числами
	int a = 10;
	a += 3; // додавання 3 до a, еквівалентно запису (a = a + 3)
	a -= 2; // віднімання 2 від a, еквівалентно запису (a = a - 2)
	a *= 4; // множення a на 4, еквівалентно запису (a = a * 4)
	a /= 2; // ділення a на 2, еквівалентно запису (a = a / 2)
	a %= 3; // остача від ділення a на 3, еквівалентно запису (a = a % 3)

	// робота з рядками 
	string surname = "Тарарук";
	name += " Сюзанна"; // додавання рядка

	// робота з символами
	char ch = 'A';
	c += 1; // перехід до наступної літери

	// робота з циклами
	for (int i = 2; i <= 10; i += 2) { // ефективно додає 2 до лічильника
		cout << i << endl;
	}

	// робота з булевими значеннями
	bool isAnimal = true;
	isAnimal = !isAnimal; // інвертує булеве значення

	// = використовується для повної заміни значень
	// складенні оператори (+=, -=, *=, /=, %=) дуже зручні і ефективні при зміні значення змінної 
	// відносно початкового стану, вони роблять код коротшим та атамарним

	return 0;
}