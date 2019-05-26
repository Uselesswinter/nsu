
#include <iostream> 

int main()
{
	int a;
	printf("Insert the number\n");
	scanf_s("%i", &a);
	for (int i = 2; i <= a; i++)
	{
		int k = 0;
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				k++;
			}
		}
		if (k == 0)
		{
			printf("%i\n", i);
		}
	}
	system("pause");
	return 0;
}