#include <iostream>

using namespace std;

void main(void) {
	int a = 2, b = 5;
	void obmen(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "äî îáěĺíŕ: a= " << a << " b= " << b << endl;
	obmen(a, b);
	cout << "ďîńëĺ îáěĺíŕ: a= " << a << " b= " << b << endl;
	obmen2(&a, &b);
	cout << "ďîńëĺ îáěĺíŕ2: a= " << a << " b= " << b << endl;
	obmen3(a, b);
	cout << "ďîńëĺ îáěĺíŕ3: a= " << a << " b= " << b << endl;
}
// Îáěĺí ďî çíŕ÷ĺíčţ
void obmen(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
// Îáěĺí ďî óęŕçŕňĺë˙ě
void obmen2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// Îáěĺí ďî ńńűëęŕě
void obmen3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
