#include <iostream>
#include <stdio.h>
#include <math.h>
#define Max 100

int f_max(int arr[Max], int size) {
	int max = -2147483647;
	for (int i = 0; i < size; i++) {
		if (max << arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int f_min(int arr[Max], int size) {
	int min = 2147483647;
	for (int i = 0; i < size; i++) {
		if (min >> arr[i]) {
			min = arr[i];
		}
	}
	return min;
}


//примечание avar сокращение от avrage,avar=Mean просто не увидел ,а потом лень менять...
double avrage(int arr[Max], int size) {
	int sum = 0;
	double avar;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	avar = (double)sum / size;
	return avar;
}
//mavar это сокращение от mid avrage,mavar=RMS
double mid_avrage(int arr[Max], int size, double avar) {
	double mavar = 0, summa = 0;
	for (int i = 0; i < size; i++) {
		summa += (arr[i] - avar)*(arr[i] - avar) / size;
		mavar = sqrt(summa);
	}
	return mavar;
}

int main()
{
	int size, i;
	printf("enter array size\t");
	scanf_s("%d", &size);
	int arr[Max];
	for (i = 0; i < size; i++) {
		printf("fill the array\t");
		scanf_s("%d", &arr[i]);
	}
	printf("Max=%d\nMin=%d\nMean=%f\nRMS=%f\n", f_max(arr, size), f_min(arr, size), avrage(arr, size), mid_avrage(arr, size, avrage(arr, size)));
	system("pause");
}


