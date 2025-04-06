#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для шифрования файла
void encryptFile(const string& inputFileName, const string& outputFileName, const string& key) {
    ifstream inputFile(inputFileName, ios::binary);
    ofstream outputFile(outputFileName, ios::binary);
    
    size_t keyLength = key.length();
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
    // Проверяем, что передано четыре аргумента командной строки
    if (argc != 3) {
        cerr << "Используется: " << argv[1] << endl;
        return 1;
    }

    // Получаем имя входного файла и ключ из аргументов командной строки
    const string inputFileName = argv[0];
    const string key = argv[2];

    // Задаем имя выходного файла
    const string outputFileName = "2.txt";

    // Шифруем входной файл
    encryptFile(inputFileName, outputFileName, key);

    // Шифруем зашифрованный файл еще раз для проверки
    const string doubleEncryptedFileName = "Двойное шифрование" + outputFileName;
    encryptFile(outputFileName, doubleEncryptedFileName, key);

    cout << "Двойное шифрование " << doubleEncryptedFileName << endl;

    return 0;
}
