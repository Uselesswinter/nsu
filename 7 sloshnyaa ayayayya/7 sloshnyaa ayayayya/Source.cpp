#include <stdio.h> 
#include "math.h" 
#include "stdlib.h" 
int Compare(int arr[], int i) {
	int flag = 0;
	if (arr[i] > arr[i + 1]) {
		flag = 1;
	}
	return flag;

}
void Replace(int arr[], int j) {
	int tmp = 0;
	tmp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = tmp;

}
void sort_array(int arr[], int count) {
	int flag = 0;
	for (int i = 0; i < count; i++) {
		flag = 0;
		for (int j = 0; j < count - i - 1; j++) {
			flag = Compare(arr, j);
			if (flag == 1) {
				Replace(arr, j);
			}
		}
	}
}

int main()
{
	int max, min;
	int* parr;
	int Count;
	printf("Input elements count: ");
	scanf_s("%d", &Count);
	parr = (int*)malloc(sizeof(int)*Count);
	if (parr == NULL)
	{
		printf("Can’t allocate memory!");
	}
	for (int i = 0; i < Count; i++) {
		scanf_s("%d", (parr + i));
	}
	sort_array(parr, Count);
	for (int i = 0; i < Count; i++) {
		printf("%d\t", *(parr + i));
	}
	free(parr);
	system("pause");
	return 0;
}