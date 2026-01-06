#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    string text1 = "Hello";
    string text2 = "World";
    cout << "Перший рядок: " << text1 << endl;
    cout << "Другий рядок: " << text2 << endl;

    string combined = text1 + " " + text2;
    cout << "Після конкатенації: " << combined << endl;

    int length = combined.length();
    cout << "Довжина рядка: " << length << endl;

    char ch = combined[1]; 
    cout << "Символ за індексом 1: " << ch << endl;

    combined[0] = 'h';
    cout << "Рядок після зміни символа: " << combined << endl;

    string s;
    cout << "Введіть рядок для перевірки паліндрому: ";
    cin >> s;

    if (IsPalindrome(s)) {
        cout << "це паліндром" << endl;
    }
    else {
        cout << "це не паліндром" << endl;
    }

    return 0;
}
