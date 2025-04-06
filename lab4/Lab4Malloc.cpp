#include <iostream>
#include <cstring>
#include <cstdlib>


int dlina1(const char*);
int dlina2(const char*);
int dlina3(const char*);
void kopir(char*, const char*);
int sravn(const char*, const char*);
char konkat(char*, const char*);

using namespace std;

int main() {
    char* str1, * str2, * str3;
    str1 = (char*)malloc(100 * sizeof(char));
    str2 = (char*)malloc(100 * sizeof(char));
    str3 = (char*)malloc(100 * sizeof(char));

    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << "Dlina str1=" << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
    cout << "Dlina str1=" << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
    cout << "Dlina str1=" << dlina3(str1) << ", str2=" << dlina3(str2) << endl;

    kopir(str3, str1);
    cout << "kopir str1 v str3. str3 = " << str3 << endl;

    int result = sravn(str1, str2);
    cout << "sravn str1 & str2: " << result << endl;

    char str4 = konkat(str1, str2);
    cout << "konkat str1 & str2: " << str1 << endl;

}

// Первая фукция длинны
int dlina1(const char* str) {

    int length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}
// Вторая фукция длинны
int dlina2(const char* str) {
    const char* s = str;
    while (*s) ++s;
    return s - str;
}
// Третья фукция длинны
int dlina3(const char* str) {

    int length = 0;
    while (*str++) length++;
    return length;
}
//Функция копирования
void kopir(char* dest, const char* src) {
    while ((*dest++ = *src++));
}
//Функция сравнения
int sravn(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
//Функция конкатенации
char konkat(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return *dest;
}
