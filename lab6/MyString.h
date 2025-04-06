#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

class MyString {
private:
    char* data; // Переменная для хранения символов строки

public:
    // Конструкторы
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);

    // Деструктор
    ~MyString();

    // Перегруженные операции
    MyString& operator=(const MyString& other);
    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;

    // Метод для определения длины строки
    size_t length() const;

    // Методы ввода и вывода строки
    friend ostream& operator<<(ostream& os, const MyString& str);
    friend istream& operator>>(istream& is, MyString& str);
};

#endif // MYSTRING_H