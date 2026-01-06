#include <iostream>
#include <windows.h>
using namespace std;

int Sum(int a, int b) {
    return a + b;
}

bool IsPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool IsPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++; 
        right--;
    } 
    return true;
}

// Ітеративний метод обчислення факторіалу, використовується тип long long для зберігання більших значень
// максимальне значення для факторіалу 20! = 2432902008176640000, що вміщується в long long
long long Factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double Average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

// рекурсивний метод обчислення Фібоначчі дуже повільний для великих n, тип long (32-бітний на Windows) може зберігати значення
// до 46-го елемента Фібоначчі, також можна було б використати ітеративний метод або мемоізацію для покращення продуктивності
// також можна використати тип long long (64-бітний на Windows) для більших значень, тоді він буде вміщувати до 92-го елемента Фібоначчі
long Fibonacci(long n) {
    if (n <= 1) {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, n;
	string text;

    cout << "Введіть два числа для обчислення суми: ";
    cin >> a >> b;
    cout << "Сума = " << Sum(a, b) << "\n" << endl;

    cout << "Введіть рядок для перевірки на паліндромність: ";
    cin >> text;

    if (IsPalindrome(text)) {
        cout << "Це паліндром" << endl;
    }
    else {
        cout << "Це не паліндром" << endl;
    }

    cout << "Введіть число для перевірки на простоту: ";
    cin >> n;
    if (IsPrime(n)) {
        cout << n << " просте число\n" << endl;
    }
    else {
        cout << n << " НЕ є простим числом.\n" << endl;
    }

    cout << "Введіть число для обчислення факторіалу (до 20): ";
    cin >> n;
    if (n > 20) {
		cout << "Занадто велике число для обчислення факторіалу" << endl;
    }
    else if (n < 0) {
        cout << "Факторіал не визначений для від'ємних чисел.\n" << endl;
    }
    else {
        cout << "Факторіал = " << Factorial(n) << "\n" << endl;
    }
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Введіть елементи масиву: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Середнє арифметичне = " << Average(arr, size) << "\n" << endl;
    delete[] arr;

	cout << "Введіть номер елемента Фібоначчі (до 46): "; // обмеження для уникнення переповнення long
    cin >> n;
    if (n > 46){
        cout << "Занадто велике число для обчислення Фібоначчі рекурсивно" << endl;
        
    }
    else if (n < 0) {
        cout << "Число не може бути відємним" << endl;
    }
    else{
        cout << "Fibonacci(" << n << ") = " << Fibonacci(n) << endl;
	}
    

    cout << "Програма завершена" << endl;
    return 0;
}
