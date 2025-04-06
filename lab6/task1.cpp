#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* data; 

public:
    // Конструкторы
    MyString() : data(nullptr) {} 
    MyString(const char* str) {
        if (str != nullptr) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }
        else {
            data = nullptr;
        }
    }
    MyString(const MyString& other) { // Конструктор копирования
        if (other.data != nullptr) {
            data = new char[strlen(other.data) + 1]; 
            strcpy(data, other.data);
        }
        else {
            data = nullptr;
        }
    }

    
    ~MyString() {
        delete[] data;
    }

    // Перегруженные операции
    MyString& operator=(const MyString& other) { 
        if (this != &other) {
            delete[] data;
            if (other.data != nullptr) {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }
    MyString operator+(const MyString& other) const { // Операция сцепления строк
        MyString result;
        if (data != nullptr && other.data != nullptr) {
            result.data = new char[strlen(data) + strlen(other.data) + 1];
            strcpy(result.data, data);
            strcat(result.data, other.data);
        }
        else if (data != nullptr) {
            result = *this;
        }
        else if (other.data != nullptr) {
            result = other;
        }
        return result;
    }
    bool operator==(const MyString& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Метод для определения длины строки
    size_t length() const {
        return (data != nullptr) ? strlen(data) : 0;
    }

    // Методы ввода и вывода строки
    friend ostream& operator<<(ostream& os, const MyString& str) { // Операция вывода
        if (str.data != nullptr) {
            os << str.data;
        }
        return os;
    }
    friend istream& operator>>(istream& is, MyString& str) { // Операция ввода
        char buffer[1024];
        is >> buffer;
        str = MyString(buffer);
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "ru"); 
    MyString str1("ASDSDFDSF");
    MyString str2("ASDASDDAS");

    MyString str3 = str1 + str2;
    cout << "Объединенная строка: " << str3 << endl;

    if (str1 == str2) {
        cout << "Строки равны: " << endl;
    }
    else {
        cout << "Строки не равны:" << endl;
    }

    cout << "Длина строки:" << str1.length() << endl;

    MyString str4;
    cout << "Введите: ";
    cin >> str4;
    cout << "Введенная строка:" << str4 << endl;

    return 0;
}