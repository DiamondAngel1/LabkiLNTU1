#include <iostream>
#include <string>
#include <sstream>   // для розбиття рядка на слова за допомогою stringstream
#include <algorithm> // для reverse()
#include <windows.h> 
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    stringstream ss1(text);
    string word;
    int wordCount = 0;
	while (ss1 >> word) { // прочитує кожне слово з рядка, присвоює його змінній word і збільшує лічильник для підрахунку кількості слів
        wordCount++;
    }

	string* words = new string[wordCount]; // динамічний масив для зберігання слів

    stringstream ss2(text);
    int i = 0;
	while (ss2 >> word) { // знову читає слова з рядка і зберігає їх у масиві words
        words[i++] = word;
    }

    cout << "\nКількість слів: " << wordCount << endl;

    string upperText = text;
    string lowerText = text;

	for (char& c : upperText) { // створюється посилання на кожен символ рядка і перетворює його на верхній регістр
        c = toupper(c);
    }
	for (char& c : lowerText) { // створюється посилання на кожен символ рядка і перетворює його на нижній регістр
        c = tolower(c);
    }

    cout << "У верхньому регістрі: " << upperText << endl;
    cout << "У нижньому регістрі: " << lowerText << endl;

    cout << "Слова окремо:" << endl;
	for (int i = 0; i < wordCount; i++) { // виводить кожне слово з масиву на окремому рядку
        cout << words[i] << endl;
    }

	reverse(words, words + wordCount); // використовує алгоритм reverse() для зміни порядку слів у масиві на зворотний
    cout << "Рядок зі словами у зворотному порядку: "; 
    for (int j = 0; j < wordCount; j++) {
        cout << words[j];
        if (j < wordCount - 1) {
            cout << " ";
        }
    }

    delete[] words; 

    return 0;
}
