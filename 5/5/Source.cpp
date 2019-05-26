//h=(b-a)/N
//x(i)=a+i*(b-a)/N
//f=x*x*x-x
#include <stdio.h>
#include <iostream>
#include <math.h>

double func(double x)
{
	double f;
	f = x * x*x - x;
	return f;
}
//double func2(double) 


int main()
{
	int a, b, N, i;
	printf("a, b chapels of integration, N number of partitions\n");
	printf("enter the limits of integration and the number of breaks\t");
	scanf_s("%d\t%d\t%d", &a, &b, &N);
	double I = 0, f1 = 0, f2 = 0, x = 0;
	for (i = 0; i <= N; i++) {
		x = a + i * (double)(b - a) / N;
		f1 = func(x);
		x = a + (i + 1) * (double)(b - a) / N;
		f2 = func(x);
		I = I + ((double)(b - a) / N)*(f1 + f2) / 2;
	}
	printf("integral equals about I=%f", I);
	system("pause");
	return 0;
}