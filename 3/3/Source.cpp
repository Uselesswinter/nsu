#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	int accuracy = 0;
	printf("enter up to which date you shoupd get pi\t");
	scanf_s("%d", &accuracy);
	float restriction;
	restriction = powf(10, (-1)*(accuracy));
	long double pi = 0;
	long double lshe_pi = 0;
	float i = 0;
	do {
		i = i++;
		lshe_pi = pi;
		pi = pi + 4 * (1 / ((2 * i) - 1))*(powf(-1, (i + 1)));
	} while ((pi - lshe_pi)*(pi - lshe_pi) > restriction*restriction);
	printf("pi %.*lf", accuracy, pi);
	system("pause");
	return 0;
}