#include "stdlib.h"
#include "stdio.h" 
#include "math.h" 

int main()
{
	float a, b, c;
	printf("Enter integer coefficients a, b, c for quadratic equation ax^2+bx+c=0\n");
	scanf_s("%f%f%f", &a, &b, &c);
	if (a != 0)
	{
		float Dis;
		Dis = b * b - 4 * a*c;
		if (Dis < 0)
		{
			printf("only complex roots\n");
		}
		else
		{
			float root1, root2;
			root1 = ((-1)*b + sqrt(Dis)) / 2;
			root2 = ((-1)*b - sqrt(Dis)) / 2;
			if (root1 == root2)
			{
				printf("x=%f\n", root1);
			}
			else
			{
				printf("x1=%f x2=%f\n", root1, root2);
			}

		}

	}
	else
	{
		if (b == 0)
		{
			printf("Incorrect data entry\n");
		}
		else
		{
			float x;
			x = (-1)*c / b;
			printf("x=%f\n", x);
		}
	}
	system("pause");
	return 0;
}