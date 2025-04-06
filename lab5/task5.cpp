#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для шифрования файла
void encryptFile(const string& inputFileName, const string& outputFileName, const string& key) {
    ifstream inputFile(inputFileName, ios::binary);
    ofstream outputFile(outputFileName, ios::binary);

    // Получаем длину ключа
    size_t keyLength = key.length();
    // Индекс текущего символа ключа
    size_t keyIndex = 0;

    char c;
    // Считываем символы из входного файла
    while (inputFile.get(c)) {
        c ^= key[keyIndex];
        outputFile.put(c);
        keyIndex = (keyIndex + 1) % keyLength;
    }

    // Закрываем файлы
    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]) {
    // Проверяем, что передано три аргумента командной строки
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <output_file> <key>" << endl;
        return 1;
    }

    // Имя выходного файла и ключ из аргументов командной строки
    const string outputFileName = argv[1];
    const string key = argv[2];

    encryptFile("1.txt", outputFileName, key);

    // Повторно шифруем зашифрованный файл для проверки
    const string doubleEncryptedFileName = outputFileName;
    encryptFile(outputFileName, doubleEncryptedFileName, key);

    cout << "Двойное шифрование:" << doubleEncryptedFileName << endl;

    return 0;
}
