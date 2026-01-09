#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <direct.h>
#include <windows.h>
#include <string>
using namespace std;

#pragma pack(push, 1) // pragma pack використовується для вирівнювання структур у пам'яті без додаткових відступів

struct BMPFileHeader { // структура заголовка BMP файлу
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BMPInfoHeader { // структура інформаційного заголовка BMP файлу
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop) // pragma pack(pop) повертає попередні налаштування вирівнювання

struct RGB { // структура для зберігання кольору пікселя у форматі BGR
    char b, g, r;
};

// Функція для створення м’якого переходу кольору в трикутнику
double smoothEdge(int x, int y, int width, int height) {
    double dx = abs(x - width / 2.0);
    double dy = height - y;
    double dist = sqrt(dx * dx + dy * dy);
    return exp(-dist / (width / 7.0));
}

// Функція для генерації унікального імені файлу
string generateFilename() {
    int counter = 1;
    string filename = "images/triangle.bmp";
	while (ifstream(filename).good()) { // перевіряємо, чи файл існує, ifstram відкриває файл для читання, good() повертає true, якщо файл успішно відкрито
        counter++;
        filename = "images/triangle" + to_string(counter) + ".bmp";
    }
    return filename;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int width;
    cout << "Введіть ширину трикутника (пікселі): ";
    cin >> width;

    int height = width / 2;
	vector<vector<RGB>> image(height, vector<RGB>(width)); // створюємо 2D вектор для зберігання пікселів з розмірами height x width

	// Заповнення пікселів трикутника з м’якими краями
    for (int y = 0; y < height; y++) {
        int left  = (width / 2) - (y * width) / (2 * height);
        int right = (width / 2) + (y * width) / (2 * height);

        for (int x = 0; x < width; x++) {
            if (x >= left && x <= right) {
                double alpha = smoothEdge(x, y, width, height);
                image[y][x] = {
                    (char)(255 * alpha),
                    (char)(255 * alpha),
                    (char)(255 * alpha)
                };
            } else {
                image[y][x] = {0, 0, 0};
            }
        }
    }

	_mkdir("images"); // створюємо папку, якщо її немає за допомогою _mkdir з direct.h
    string filename = generateFilename();

	// ініціалізація заголовків BMP файлу
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

	// обчислення розмірів рядка та даних з урахуванням вирівнювання до кратного 4 байтам
    int rowSize = (3 * width + 3) & ~3;
    int dataSize = rowSize * height;

	// заповнення заголовків BMP файлу та інформаційного заголовка
    fileHeader.bfType = 0x4D42;
    fileHeader.bfSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + dataSize;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

    infoHeader.biSize = sizeof(BMPInfoHeader);
    infoHeader.biWidth = width;
    infoHeader.biHeight = height;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = dataSize;
    infoHeader.biXPelsPerMeter = 0;
    infoHeader.biYPelsPerMeter = 0;
    infoHeader.biClrUsed = 0;
    infoHeader.biClrImportant = 0;

	ofstream fout(filename, ios::binary); // ofstream для запису у бінарному режимі, в дужках вказується ім'я файлу та режим відкриття (ios::binary - бінарний режим)
    if (!fout.is_open()) {
        cout << "Не вдалося створити файл" << endl;
        return 1;
    }

	// запис заголовків та пікселів у файл, char* використовується для приведення вказівника до типу char, оскільки метод write() приймає вказівник на char, 
	// & використовується для отримання адреси змінної fileHeader та infoHeader, sizeof() повертає розмір структури в байтах
    fout.write((char*)&fileHeader, sizeof(fileHeader)); 
    fout.write((char*)&infoHeader, sizeof(infoHeader));

	for (int y = height - 1; y >= 0; y--) { // BMP зберігає пікселі знизу вгору, тому починаємо з останнього рядка
		for (int x = 0; x < width; x++) { 
			fout.write((char*)&image[y][x], 3); // записуємо 3 байти (B, G, R) для кожного пікселя
        }
		int padding = rowSize - width * 3; // обчислення кількості додаткових байтів для вирівнювання до кратного 4
		for (int p = 0; p < padding; p++) { // заповнюємо додаткові байти нулями
			fout.put(0);// записуємо один байт зі значенням 0
        }
    }

	fout.close(); // закриваємо файл після запису
    cout << "Файл " << filename << " успішно створено" << endl;

    return 0;
}
