    #include <stdlib.h>
    #include "stdio.h"
    char Bol(char x[70]) // Dlya zaglavnih bukv
    {
        if (x[0] >= 'a' && x[0] <= 'z')
        {
            x[0] = x[0] + 'A' - 'a';
        }
        for (int i = 1; i <= 70; i++)
        {
            if (x[i] >= 'A' && x[i] <= 'Z' && x[i - 2] != '.')
            {
                x[i] = x[i] - 'A' + 'a';
            }
            if (x[i] >= 'a' && x[i] <= 'z' && x[i - 2] == '.')
            {
                x[i] = x[i] - 'a' + 'A';
            }
        }
        return(x[70]);
    }

    char Del(char x[70]) // Udalenie lishnih probelov
    {
        for (int i = 0; i < 70; i++)
        {
            if (x[0] == ' ')
            {
                for (int q = i; q < 70; q++)
                {
                    x[q] = x[q + 1];
                }
                i = i - 1;
            }
            if (x[i] == ' ')
            {

                if (x[i] == x[i + 1])
                {
                    for (int q = i; q < 70; q++)
                    {
                        x[q] = x[q + 1];
                    }
                    i = i - 1;
                }
            }

        }
        return(x[70]);
    }

    char Del1(char x[70]) // Udalenie probelov pered tochkoy i zapyatoy
    {
        for (int i = 0; i < 70; i++)
        {
            if (x[i] == '.' || x[i] == ',')
            {
                if (x[i - 1] == ' ')
                {
                    for (int q = i; q < 70; q++)
                    {
                        x[q - 1] = x[q];
                    }
                    i = i - 1;
                }
            }
        }
        return(x[70]);
    }

    char Del2(char x[70]) // Dobavlenie probelov posle znaka prepinaniya
    {
        for (int i = 0; i < 70; i++)
        {
            if (x[i] == ',' || (x[i] == '.' && x[i + 1] != '.'))
            {
                if (x[i + 1] != ' ')
                {
                    for (int q = 69; q > i; q--)
                    {
                        x[q] = x[q - 1];
                    }
                    x[i + 1] = ' ';

                }
            }

        }
        return(x[70]);
    }



int main()
{
	printf("Vvedite text do 70 simvolov!\n");
	char a[70];
	fgets(a, 70, stdin);
	a[70] = Del(a);
	a[70] = Del1(a);
	a[70] = Del2(a);
	a[70] = Bol(a);
	printf("%s\n", a);
	system("pause");
	return 0;
}