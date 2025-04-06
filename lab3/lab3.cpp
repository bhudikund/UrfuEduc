#include <iostream>
#include <conio.h>

#define N 12

using namespace std;

void bubbleSort(int[]);
void quickSort(int[], int, int);

void main(void) {
	int mas[] = { 2,5,-8,1,-4,6,3,-5,-9,13,0,4,9 };
	int imin, imax;
	int n = sizeof(mas) / sizeof(int);
	int i;
	imin = i = 0; imax = i = 0;
	for (int i = 0; i < n; i++) {
		cout << mas[i] << ' ';
	}
	cout << endl;
	bubbleSort(mas);
	
	//новый массив для быстрой сортировки
	int array[] = { 2,5,-8,1,-4,6,3,-5,-9,13,0,4,9 };
	quickSort(array, 0, n - 1);
	cout << "quickSort : ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	for (i = 0; i < n - 1; i++) {
		imin = i;
		for (int j = i + 1; j < n; j++) {
			if (mas[j] < mas[imin]) imin = j;
		}
		int t = mas[i];
		mas[i] = mas[imin];
		mas[imin] = t;
	}

	for (i = 0; i < n; i++) {
		cout << mas[i] << ' ';
	}
	cout << endl;
}

//функция сортировки пузырьком
void bubbleSort(int array[N]) {
	int temp;	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (array[j] > array[j + 1]) {//проверка на меньший элемент в данном индексе и последующая перестановка, если true
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "bubble sort : ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

//быстрая сортировка
void quickSort(int array[N], int left, int right) {
	if (left >= right) return;
	int pivot = array[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;
		if (i <= j) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	quickSort(array, left, j);
	quickSort(array, i, right);
}




