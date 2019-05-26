// f:3 * x - cos(x) - 1 = 0
// df:3+sin(x)=0
//x=x-F(x)/dF(x)
#include <stdio.h>

#include <iostream>
#include <math.h>

double func(double x)
{
	double f;
	f = 3 * x - cos(x) - 1;
	return f;
}
double dfunc(double x)
{
	double df;
	df = 3 + sin(x);
	return df;
}

int main()
{
	double start = 0, finish = 0;
	printf("enter your section\t");
	scanf_s("%f%f", &start, &finish);
	int accuracy = 0;
	printf("enter accuracy\t");
	scanf_s("%d", &accuracy);
	double x = start;
	double last_x = 0;
	double f1 = 0, f2 = 0;
	do {
		double f = 0, df = 0;
		f = func(x);
		df = dfunc(x);
		last_x = x;
		x = x - f / df;
		f1 = abs(x - last_x);
		f2 = powf(10, (-1)*accuracy);
	} while (f1 > f2);
	printf("%.*f", accuracy, x);
	system("pause");
	return 0;
}