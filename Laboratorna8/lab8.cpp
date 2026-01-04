#include <stdio.h>
#include <stdlib.h> // для system("CLS" для windows) або system("clear" для linux або macOS)
#include <ctime> 
#include <iostream>
#include <windows.h>
#define SIZE 10 // визначення розміру масиву
using namespace std;

void PrintArr(char arr[], int index, int score) { // Функція для виведення масиву з поточною позицією
	system("cls");// Очищення поточного екрану

	cout << "Переміщуйте курсор a-вліво d-вправо (Q - вихід): " << endl;
	cout << "Зібрано X: " << score << endl;
	for (int i = 0; i < SIZE; i++) {
		if (i == index) {
			cout << "*"; // Поточна позиція
		}
		else {
			cout << arr[i]; // Інші елементи
		}
	}
	cout << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL)); // Ініціалізація генератора випадкових чисел

	char arr[SIZE];
	int index = 0;
	int ch;
	int score = 0;
	// Ініціалізація масиву
	for (int i = 0; i < SIZE; i++) {
		arr[i] = '-';
	}
	int xRand = rand() % SIZE; // Випадкова позиція для 'X' залежно від розміру масиву
	arr[xRand] = 'X';
	// я використала керування клавішами 'a' і 'd', а не стрілками, тому, що getchar() з <stdio.h> 
	// не читає спеціальні клавіші, стрілки не є ASCII-символами і не надходять у стандартний ввід у звичайному режимі консолі Windows,
	// тому getchar() їх не бачить.
	while (true) {
		PrintArr(arr, index, score); // Виводимо масив

		ch = getchar();

		if (ch == 97) {
			if (index > 0) {
				index--;
			}
		}
		else if (ch == 100) {
			if (index < SIZE - 1) {
				index++;
			}
		}
		else if (ch == 'q' || ch == 'Q') {
			break;
		}
		if (arr[index] == 'X') {
			score++; 
			arr[index] = '-';
			int newX; 
			do { // Генеруємо нову позицію для 'X'
				newX = rand() % SIZE;
			}
			while (newX == index); // не ставимо X під курсор
			arr[newX] = 'X'; 
		}
	}

	cout << "\nПрограма завершена" << endl;;
	return 0;
}



// Альтернативний варіант програми з використанням бібліотеки <conio.h> який дозволяє використовувати стрілки клавіатури
//
//#include <stdlib.h> 
//#include <conio.h>  // Для _getch() та обробки спеціальних клавіш (Windows)
//#include <iostream>
//#include <ctime> 
//#include <windows.h>
//#define SIZE 10
//using namespace std;   
//
//void PrintArr(char arr[], int index, int score) {
//    system("cls");
//
//    cout << "Переміщуйте курсор стрілками (Q - вихід): " << endl;
//	cout << "Зібрано X: " << score << endl;
//    for (int i = 0; i < SIZE; i++) {
//        if (i == index) {
//            cout << "*";
//        }
//        else {
//            cout << arr[i];
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    
//    char arr[SIZE];
//    int index = 0;
//    int ch; 
//	int score = 0;
//
//    for (int i = 0; i < SIZE; i++) {
//        arr[i] = '-';
//    }
//
//	int xRand = rand() % SIZE;
//	arr[xRand] = 'X';
//
//    while (true) {
//        PrintArr(arr, index, score); 
//
//        ch = _getch(); // Читаємо символ без ехо (з конio.h)
//
//        // Обробка спеціальних клавіш стрілок 
//        if (ch == 224) { // Код для спеціальних клавіш (стрілки, F1-F12 тощо)
//            ch = _getch(); // Читаємо другий байт коду 
//            if (ch == 75) { // 224 75 - Стрілка вліво
//                if (index > 0) {
//                    index--;
//                }
//            }
//            else if (ch == 77) { // 224 77 - Стрілка вправо
//                if (index < SIZE - 1) {
//                    index++;
//                }
//            }
//        }
//        else if (ch == 'q' || ch == 'Q') {
//            break;
//        }
//		if (arr[index] == 'X') {
//			score++;
//			arr[index] = '-';
//			int newX;
//			do { // Генеруємо нову позицію для 'X'
//				newX = rand() % SIZE;
//			} while (newX == index); // не ставимо X під курсор
//			arr[newX] = 'X';
//		}
//    }
//
//    cout << "\nПрограма завершена" << endl;;
//    return 0;
//}
