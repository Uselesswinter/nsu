#include<iostream>
#define _CRT_SECURE_NO_WARNINGS 
struct list {
	char* s;
	list* p;
};

void Bol(char** x) // Dlya zaglavnih bukv
{
	if ((*x)[0] >= 'a' && (*x)[1] <= 'z')
	{
		(*x)[0] = (*x)[0] + 'A' - 'a';
	}
	for (int i = 1; i <= strlen(*x); i++)
	{
		if ((*x)[i] >= 'A' && (*x)[i] <= 'Z' && (*x)[i - 2] != '.')
		{
			(*x)[i] = (*x)[i] - 'A' + 'a';
		}
		if ((*x)[i] >= 'a' && (*x)[i] <= 'z' && (*x)[i - 2] == '.')
		{
			(*x)[i] = (*x)[i] - 'a' + 'A';
		}
	}
}

void Del(char** x) // Udalenie lishnih probelov
{
	for (int i = 0; i < strlen(*x); i++)
	{
		if ((*x)[0] == ' ')
		{
			for (int q = i; q < strlen(*x); q++)
			{
				(*x)[q] = (*x)[q + 1];
			}
			i = i - 1;
		}
		if ((*x)[i] == ' ')
		{

			if ((*x)[i] == (*x)[i + 1])
			{
				for (int q = i; q < strlen(*x); q++)
				{
					(*x)[q] = (*x)[q + 1];
				}
				i = i - 1;
			}
		}

	}
}

void Del1(char** x) // Udalenie probelov pered tochkoy i zapyatoy
{
	for (int i = 0; i < strlen(*x); i++)
	{
		if ((*x)[i] == '.' || (*x)[i] == ',')
		{
			if ((*x)[i - 1] == ' ')
			{
				for (int q = i; q < strlen(*x); q++)
				{
					(*x)[q - 1] = (*x)[q];
				}
				i = i - 1;
			}
		}
	}
}

void Del2(char** x) // Dobavlenie probelov posle znaka prepinaniya
{
	for (int i = 0; i < strlen(*x); i++)
	{
		if ((*x)[i] == ',' || ((*x)[i] == '.' && (*x)[i + 1] != '.'))
		{
			if ((*x)[i + 1] != ' ')
			{
				for (int q = strlen(*x)-1; q > i; q--)
				{
					(*x)[q] = (*x)[q - 1];
				}
				(*x)[i + 1] = ' ';

			}
		}

	}
}


int main(){
	list* head;
	FILE* f;
	printf("enter command\n 1-console enter\n 2-file enter\n");
	int k;
	int read = 0;
	scanf_s("%d", &k);
	if (k == 1) f = stdin;
	else fopen_s(&f, "text.txt", "r");
	list* cur = (list*)malloc(sizeof(list));
	head = cur;
	do {
		cur->s = (char*)malloc(sizeof(char));
		read+=(int)fread(cur->s,sizeof(char),1,f);
		cur->p = (list*)malloc(sizeof(list));
		if (cur->s[0] == '#') cur->p = NULL;
		cur = cur->p;
	} while (cur!= NULL);
	if (f != stdin)	fclose(f);
	cur = head;
	char* s = (char*)malloc((read - 1) * sizeof(char));
	k = 0;
	do {
		s[k] = cur->s[0];
		k++;
		cur = cur->p;
	} while (cur->p != NULL);
	s[k] = '\0';
	Del(&s);
	Del1(&s);
	Del2(&s);
	Bol(&s);
	printf("%s", s);
	system("pause");
	return 0;
}