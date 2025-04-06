#include <iostream>
using namespace std;

void main(void)
{
    int i, k;
    int power(int, int);
    // Вычисление  степеней от 0 до 9
    for (i = 0; i < 10; i++)
    {
        k = power(2, i);
        cout << "i = " << i << ", k = " << k << endl;
    }
}

int power(int x, int n)
{
    int i, p = 1;
    // Умножаем основание на себя n раз
    for (i = 1; i < n; i++)
    {
        p *= x;
    }
    return p;
}