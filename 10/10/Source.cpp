#include<iostream>

struct list {
	char* s;
	list* p;
};


int main(){
	list* head;
	FILE* f;
	printf("enter command\n 1-console enter\n 2-file enter\n");
	int k;
	scanf_s("%d", &k);
	if (k == 1) f = stdin;
	else fopen_s(&f, "text.txt", "r");
	list* cur = (list*)malloc(sizeof(list));
	head = cur;
	do {
		cur->s = (char*)malloc(sizeof(char));
		fread(cur->s,sizeof(char),1,f);
		cur->p = (list*)malloc(sizeof(list));
		if (cur->s[0] == '#') cur->p = NULL;
		cur = cur->p;
	} while (cur!= NULL);
	if(f!=stdin) fclose(f);
	cur = head;
	do {
			if (cur->s[0] == '#') break;
			printf("%c", cur->s[0]); 
		cur = cur->p;
	} while (cur != NULL);
	system("pause");
	return 0;
}