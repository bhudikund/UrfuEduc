#include <iostream>

using namespace std;

void main(void) {
	int a = 2, b = 5;
	void obmen(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "�� ������: a= " << a << " b= " << b << endl;
	obmen(a, b);
	cout << "����� ������: a= " << a << " b= " << b << endl;
	obmen2(&a, &b);
	cout << "����� ������2: a= " << a << " b= " << b << endl;
	obmen3(a, b);
	cout << "����� ������3: a= " << a << " b= " << b << endl;
}
// ����� �� ��������
void obmen(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
// ����� �� ����������
void obmen2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// ����� �� �������
void obmen3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}