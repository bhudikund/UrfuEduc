#include <iostream>

using namespace std;

void main(void) {
	int a = 2, b = 5;
	void obmen(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "до обмена: a= " << a << " b= " << b << endl;
	obmen(a, b);
	cout << "после обмена: a= " << a << " b= " << b << endl;
	obmen2(&a, &b);
	cout << "после обмена2: a= " << a << " b= " << b << endl;
	obmen3(a, b);
	cout << "после обмена3: a= " << a << " b= " << b << endl;
}
// Обмен по значению
void obmen(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
// Обмен по указателям
void obmen2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// Обмен по ссылкам
void obmen3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}