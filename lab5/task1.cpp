#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream in; // ����� ��� ������ ������
    string read_line = "";
    // ��������� ���� �� ������
    in.open("1.txt");


    if (in.is_open()) // ��������� ������ �� ����
    {
        cout << "���� ������ ��� ������" << endl;
        while (getline(in, read_line)) // ������� ���� ��� ������
        {
            cout << read_line << endl;
        }
    }
    else
    {
        cerr << "������, ���� �� ������" << endl;
    }
    in.close();
    return 0;
}