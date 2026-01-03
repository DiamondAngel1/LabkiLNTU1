#include <iostream>
#include <windows.h>

using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (;;) {
        int figure;
        cout << "Виберіть фігуру для виведення: " << endl;
		cout << "1 - рівнобедренний трикутник\n"
                "2 - два трикутники, вершини яких спрямовані одна до одної горизонтально\n"
                "3 - два трикутники, вершини яких спрямовані одна до одної вертикально\n"
                "0 - вихід\n";
        cin >> figure;
		if (figure == 0) {
			break;
		}
        int line = 0;
        cout << "Введіть кількість рядочків: " << endl;
        cin >> line;
		if (line <= 0) {
			cout << "Кількість рядочків повинна бути додатньою" << endl;
			continue;
		}
        switch (figure){
		case 1:
            for (int i = 1; i <= line; i++) {
                for (int j = 0; j < line - i; j++) {
                    cout << " ";
                }
                for (int k = 0; k < 2 * i - 1; k++) {
                    cout << "^";
                }
                cout << endl;
            }
			continue;
		case 2:
            for (int i = 0; i < line; i++) {
                for (int k = 0; k < 2 * i + 1; k++) {
                    cout << "^";
                }
                for (int j = 0; j < line - i - 1; j++) {
                    cout << "    ";
                }
                for (int k = 0; k < 2 * i + 1; k++) {
                    cout << "^";
                }
                cout << endl;
            }
            for (int i = line - 2; i >= 0; --i) {
                for (int k = 0; k < 2 * i + 1; k++) {
                    cout << "^";
                }
                for (int j = 0; j < line - i - 1; j++) {
                    cout << "    ";
                }
                for (int k = 0; k < 2 * i + 1; k++) {
                    cout << "^";
                }
                cout << endl;
            }
			continue;
        case 3:
            for (int i = line; i > 0; --i) {
                for (int j = 0; j < line - i; j++) {
                    cout << "  ";
                }
                for (int k = 0; k < 4 * i - 3; k++) {
                    cout << "^";
                }
                cout << endl;
            }
            for (int i = 1; i < line; i++) {
                for (int j = 0; j < line - i - 1; j++) {
                    cout << "  ";
                }
                for (int k = 0; k < 4 * i + 1; k++) {
                    cout << "^";
                }
                cout << endl;
            }
			continue;
		default:
			cout << "Ви обрали не існуючу фігуру. Спробуйте ще раз" << endl;
			continue;
        }
    }
    return 0;
}
