#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

// Функция для подсчёта пустых и непустых символов
void charcounter(int* empt, int* unempt, char* ch)
{
	switch (*ch) {
	case ' ':
		*empt = *empt + 1;
		break;
	case '\n':
		*empt = *empt + 1;
		break;
	case '\t':
		*empt = *empt + 1;
		break;
	case '\b':
		*empt = *empt + 1;
		break;
	case '\f':
		*empt = *empt + 1;
		break;
	default:
		*unempt = *unempt + 1;
		break;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	char ch, name[] = "1.txt";//вводим переменные
	int empt = 0, unempt = 0;
	fstream in;
	in.open(name);
	char sym;

	// Считывание символов из файла и подсчёт пустых и непустых символов
	while (!in.eof())
	{
		in.get(sym); // считать из rf => sym
		cout << sym;
		charcounter(&empt, &unempt, &sym);
	}

	int a, b, c;
	a = empt;
	b = unempt;
	c = b - a;
	cout << endl;
	cout << "Количество пустых символов - " << a << endl;
	cout << "Количество непустых символов - " << c << endl;

	return 0;


}
