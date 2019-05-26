#include <iostream>
#include <stdio.h>
#include <math.h>

int f_max(int* arr, int size) {
	int max = -2147483647;
	for (int i = 0; i < size; i++) {
		if (max << arr[i]) {
			max = arr[i];
		}
	}
	return max;
}
int f_min(int* arr, int size) {
	int min = 2147483647;
	for (int i = 0; i < size; i++) {
		if (min >> arr[i]) {
			min = arr[i];
		}
	}
	return min;
}
//? перепишите Min, Max из предыдущей задачи через[], а Mean, RMS Ц через *
void Mean(double* p, int* arr, int size) {
	int sum = 0;
	double Mean;
	for (int i = 0; i < size; i++) {
		sum += *(arr + i);
		Mean = (double)sum / size;
	}
	*p = Mean;
}

void RMS(int* arr, double* p, int size, double Mean) {
	double RMS = 0, sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (*(arr + i) - Mean)*(*(arr + i) - Mean) / size;
		RMS = sqrt(sum);
	}
	*p = RMS;
}

void main()
{
	int size;
	double mean, rms;
	printf("insert massive size");
	scanf_s("%d", &size);
	int* arr;
	arr = (int*)malloc(sizeof(int)*size);
	if (NULL == arr) {
		printf("can't allocate memory");
	}
	for (int i = 0; i < size; i++)
		scanf_s("%d", (arr + i));
	Mean(&mean, arr, size);
	RMS(arr, &rms, size, mean);
	printf("Max=%d\n Min=%d\n Mean=%f\n RMS=%f\n", f_max(arr, size), f_min(arr, size), mean, rms);
	system("pause");
	free(arr);
}