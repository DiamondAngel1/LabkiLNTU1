#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

long long Factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

long Fibonacci(long n) {
    if (n <= 1) {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// НСД за алгоритмом Евкліда 
// НСД(a, b) = НСД(b, a % b), поки другий аргумент не стане 0.
int NSD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return NSD(b, a % b);
}

long long Stepin(long long a, int n) {
    if (n == 0) {
        return 1;
    }
    return a * Stepin(a, n - 1);
}

int SumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + SumDigits(n / 10);
}

int BinarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        return mid;
    }
    if (target < arr[mid]) {
        return BinarySearch(arr, left, mid - 1, target);
    }
    return BinarySearch(arr, mid + 1, right, target);
}

int SumArray(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    return arr[size - 1] + SumArray(arr, size - 1);
}

bool IsPalindrome(const string& s, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (s[left] != s[right]) {
        return false;
    }
    return IsPalindrome(s, left + 1, right - 1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть число для факторіалу (0–20): ";
    cin >> n;
    if (n < 0 || n > 20) {
        cout << "Помилка: n має бути в діапазоні 0–20, інакше буде переповнення\n" << endl;
    }
    else {
        cout << "Факторіал = " << Factorial(n) << "\n" << endl;
    }

    cout << "Введіть номер елемента Фібоначчі (до 46): ";
    cin >> n;
    if (n > 46) {
        cout << "Занадто велике число для обчислення Фібоначчі рекурсивно" << endl;

    }
    else if (n < 0) {
        cout << "Число не може бути відємним" << endl;
    }
    else {
        cout << "Fibonacci(" << n << ") = " << Fibonacci(n) << endl;
    }

    int a, b;
    cout << "Введіть два числа для НСД: ";
    cin >> a >> b;
    cout << "НСД = " << NSD(a, b) << "\n" << endl;

    cout << "Введіть число і невід’ємний степінь: ";
    cin >> a >> n;
    if (n < 0) {
        cout << "Помилка: степінь має бути невід’ємним для цілого результату\n" << endl;
    }
    else if (n > 20) {
        cout << "Увага: можливе переповнення типу long long при великому степені" << endl;
        cout << a << "^" << n << " (можливе некоректне значення): " << Stepin(a, n) << "\n" << endl;
    }
    else {
        cout << a << "^" << n << " = " << Stepin(a, n) << "\n\n";
    }

    cout << "Введіть число для суми цифр: ";
    cin >> n;
	if (n < 0) {
		cout << "Помилка: число має бути невід’ємним для суми цифр\n" << endl;
	}
    else {
        cout << "Сума цифр = " << SumDigits(n) << "\n" << endl;
    }

    int size, target;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Введіть відсортований масив:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Введіть число для пошуку: ";
    cin >> target;

    int index = BinarySearch(arr, 0, size - 1, target);
    if (index != -1) {
        cout << "Елемент знайдено на позиції: " << index << "\n" << endl;
    }  
    else {
        cout << "Елемент не знайдено\n" << endl;
    }
      
    cout << "Сума елементів масиву = " << SumArray(arr, size) << "\n" << endl;

    delete[] arr;

    string s;
    cout << "Введіть рядок для перевірки паліндрому: ";
    cin >> s;

    if (IsPalindrome(s, 0, s.length() - 1)) {
        cout << "Рядок є паліндромом " << endl;
    }
    else {
        cout << "Рядок НЕ є паліндромом " << endl;
    }
	cout << "Програма завершена" << endl;
    return 0;
}