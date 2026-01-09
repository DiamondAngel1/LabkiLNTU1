#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <windows.h>
using namespace std;


struct WAVHeader { // структура заголовка WAV файлу яка містить необхідні поля для формату PCM
    char riff[4] = { 'R','I','F','F' };
    uint32_t chunkSize;
    char wave[4] = { 'W','A','V','E' };
    char fmt[4] = { 'f','m','t',' ' };
    uint32_t subchunk1Size = 16;
    uint16_t audioFormat = 1;
    uint16_t numChannels = 1;
    uint32_t sampleRate = 44100;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample = 16;
    char data[4] = { 'd','a','t','a' };
    uint32_t subchunk2Size;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	const int sampleRate = 44100; // частота дискретизації (кількість зразків за секунду 44100 Гц)
    const int duration = 8; // тривалість 8 секунд 

	const int numChannels = 1; // моно це 1 канал, канали потрібні для того, щоб вказати скільки окремих аудіодоріжок буде у файлі
	const int bitsPerSample = 16; // глибина біт (16 біт на зразок означає, що кожен зразок може мати 65536 рівнів амплітуди)

	// Частоти нот у Гц (ноти від До до До октавою вище) 
    double freq1 = 523.25;  // До
	double freq2 = 587.33;  // Ре
	double freq3 = 659.25;  // Мі
	double freq4 = 698.46;  // Фа
	double freq5 = 783.99; // Соль
	double freq6 = 880.0;   // Ля
	double freq7 = 987.77; // Сі
	double freq8 = 1046.50; // До октавою вище

	int totalSamples = sampleRate * duration; // загальна кількість зразків вираховується як добуток частоти дискретизації на тривалість у секундах
	vector<int16_t> samples(totalSamples); // вектор для зберігання аудіо зразків у форматі 16-бітних цілих чисел 

	for (int i = 0; i < totalSamples; i++) { // генерація аудіо зразків
        double t = (double)i / sampleRate;
        double value = 0.0;
		double pi = 3.141592653589793;

        // розподіл по часових інтервалах
        if (t < 1.0) {
            value = sin(2 * pi * freq1 * t);
        }
        else if (t < 2.0) {
            value = sin(2 * pi * freq2 * t);
        }
		else if (t < 3.0)
        {
			value = sin(2 * pi * freq3 * t);
        }
        else if (t < 4.0)
        {
			value = sin(2 * pi * freq4 * t);
		}
		else if (t < 5.0)
		{
			value = sin(2 * pi * freq5 * t);
		}
		else if (t < 6.0)
		{
			value = sin(2 * pi * freq6 * t);
        }
        else if (t < 7.0) {
			value = sin(2 * pi * freq7 * t);
        }
        else {
            value = sin(2 * pi * freq8 * t);
        }

        samples[i] = (int16_t)(value * 32767); // Масштабування до амплітуди 16-біт
    }

	WAVHeader header; // ініціалізація заголовка WAV файлу та заповнення його полів
    header.numChannels = numChannels;
    header.sampleRate = sampleRate;
    header.bitsPerSample = bitsPerSample;
    header.byteRate = sampleRate * numChannels * bitsPerSample / 8;
    header.blockAlign = numChannels * bitsPerSample / 8;
    header.subchunk2Size = samples.size() * numChannels * bitsPerSample / 8;
    header.chunkSize = 36 + header.subchunk2Size;

	ofstream fout("output.wav", ios::binary); // відкриття файлу для запису у бінарному режимі
    if (!fout.is_open()) {
        cout << "Не вдалося створити файл!" << endl;
        return 1;
    }

	fout.write((char*)&header, sizeof(header)); // запис заголовка у файл
	fout.write((char*)samples.data(), samples.size() * sizeof(int16_t)); // запис аудіо зразків у файл
	fout.close(); // закриття файлу

    cout << "Файл output.wav успішно створено" << endl;
    cout << "Його можна відкрити у будь-якому аудіо плеєрі, щоб почути 8 нот від \"До\" до \"До октавою вище\"" << endl;

    return 0;
}
