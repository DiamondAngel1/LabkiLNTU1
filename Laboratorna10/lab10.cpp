#include <iostream>
#include <windows.h>
#include <ctime>
#include <algorithm>
using namespace std;
#define SIZE 5

void PrintMatrix(int arr[SIZE][SIZE]) { // функція для виводу матриці
    for (int i = 0; i < SIZE; i++) {
        cout << "|";
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] < 10) {
                cout << arr[i][j] << " | ";
                
            }
            else {
                cout << arr[i][j] << "| ";
                
            }
        }
        cout << "\n--------------------" << endl;
    }
}

void FindMinMax(int arr[SIZE][SIZE], int& minVal, int& maxVal) { // функція для пошуку мінімального та максимального знячення в матриці
    minVal = arr[0][0]; 
    maxVal = arr[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
            }
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
}

int SumElements(int arr[SIZE][SIZE]) { // функція для додавання всіх елементів матриці
    int sum = 0; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void ReplaceEvenWithZero(int arr[SIZE][SIZE]) { // функція для заміни парних елементів на нулі
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] % 2 == 0) {
                arr[i][j] = 0;
            }
        }
    }
} 

void Transpose(int arr[SIZE][SIZE]) { // функція для транспонування матриці
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void PrintZeroIndices(int arr[SIZE][SIZE]) { // функція для виводу індексів нульових елементів
    cout << "Індекси нульових елементів: " << endl; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] == 0) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int arr[SIZE][SIZE];
    int randNum = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            randNum = rand() % 20 + 1; // генерується випадкове число від 1 до 20
            arr[i][j] = randNum;
        }
    }
	cout << "Початкова матриця: " << endl;
    PrintMatrix(arr);

	int minVal, maxVal;
	FindMinMax(arr, minVal, maxVal);
	cout << "Мінімальне значення: " << minVal << endl;
	cout << "Максимальне значення: " << maxVal << endl;

	int sum = SumElements(arr);
	cout << "Сума всіх елементів: " << sum << endl;

	double average = (double)sum / (SIZE * SIZE); // обчислення середнього арифметичного
    cout << "Середнє арифметичне: " << average << endl;

	ReplaceEvenWithZero(arr);
	cout << "Матриця після заміни парних елементів на нулі: " << endl;
	PrintMatrix(arr);

    PrintZeroIndices(arr);

	Transpose(arr);
	cout << "Транспонована матриця: " << endl;
	PrintMatrix(arr);

    cout << "\nПрограма завершена" << endl;

    return 0;
}
