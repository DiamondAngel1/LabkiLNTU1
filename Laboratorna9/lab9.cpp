// Я використала conio.h для зчитування стрілок, тому що getchar() не читає спеціальні клавіші
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

#define ROW 10
#define COL 10

void PrintTable(char arr[ROW][COL], int x, int y, int score) {
    system("cls");

    cout << "Переміщуйте курсор стрілками (Q - вихід)\n";
    cout << "Зібрано X: " << score << endl;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {

            if (i == y && j == x)
                cout << "* ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    char arr[ROW][COL];
    int x = 0, y = 0;
    int score = 0;

    // Створюємо шахову таблицю з | та -
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i % 2 == 0) {
                // парний рядок: починається з '-'
                arr[i][j] = (j % 2 == 0) ? '-' : '|';
            }
            else {
                // непарний рядок: починається з '|'
                arr[i][j] = (j % 2 == 0) ? '|' : '-';
            }
        }
    }
    int xr = rand() % COL;
    int yr = rand() % ROW;
    arr[yr][xr] = 'X';

    while (true) {
        PrintTable(arr, x, y, score);

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();

            if (ch == 75 && x > 0) {
                x--;
            }
            else if (ch == 77 && x < COL - 1) {
                x++;
            }
            else if (ch == 72 && y > 0) {
                y--;
            }
            else if (ch == 80 && y < ROW - 1) {
                y++;
            }
        }
        else if (ch == 'q' || ch == 'Q') {
            break;
        }

        if (arr[y][x] == 'X') {
            score++;
            // Повернення клітинки до її шахового символу
            if (y % 2 == 0)
                arr[y][x] = (x % 2 == 0) ? '-' : '|';
            else
                arr[y][x] = (x % 2 == 0) ? '|' : '-';

            int newX, newY;
            do {
                newX = rand() % COL;
                newY = rand() % ROW;
            } while (newX == x && newY == y);

            arr[newY][newX] = 'X';
        }
    }

    cout << "\nПрограма завершена"<<endl;
    return 0;
}
