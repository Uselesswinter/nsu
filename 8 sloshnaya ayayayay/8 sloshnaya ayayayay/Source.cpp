#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include "math.h" 




struct matr {
	int M;
	int N;
	int** elm;
};

void arrayfree(struct matr cp)
{
	for (int i = 0; i < cp.N; i++) {
		free(cp.elm[i]);
	}
	free(cp.elm);
}

void arrayprint(struct matr cp)
{
	for (int i = 0; i < cp.N; i++) {
		for (int j = 0; j < cp.M; j++) {
			printf("%*d", 5, cp.elm[i][j]);
		}
		printf("\n");
	}
}

int ** matr(int** a, int n, int x) {
	int ** rp = (int **)malloc((n - 1) * sizeof(int *));
	for (int i = 0; i < n - 1; ++i)
		rp[i] = (int *)malloc((n - 1) * sizeof(int));
	for (int i = 1; i < n; ++i)
		for (int j = 0, k = 0; j < n; ++j, ++k) {
			if (j == x) {
				--k;
				continue;
			}
			rp[i - 1][k] = a[i][j];
		}
	return rp;
}

int det(int** a, int n) {
	if (n == 1)
		return a[0][0];
	if (n == 2)
		return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
	int ans = 0, sgn = 1;
	for (int i = 0; i < n; ++i) {
		ans += (sgn * a[0][i] * det(matr(a, n, i), n - 1));
		sgn *= -1;
	}
	return ans;
}

int Minor(struct matr c, int a, int b) {
	int lt = 0;
	int Str = 0;
	int det_M = 0;
	int **minor = (int **)malloc((c.N - 1) * sizeof(int *));
	for (int i = 0; i < c.N - 1; i++) {
		minor[i] = (int *)malloc((c.N - 1) * sizeof(int));
	}
	for (int i = 0; i < c.N; i++) {
		for (int j = 0; j < c.M; j++) {
			if (i != a && j != b) {
				if (lt == c.N - 1) {
					lt = 0;
					Str++;
				}
				minor[lt][Str] = c.elm[i][j];
				lt++;
			}
		}
	}
	det_M = det(minor, c.N - 1);
	free(minor);
	return det_M;
}

void inv(struct matr cp) {
	float zn_1 = 0;
	float zn_2 = 0;
	float **ans = (float **)malloc(cp.N * sizeof(int *));
	for (int i = 0; i < cp.N; i++) {
		ans[i] = (float *)malloc(cp.N * sizeof(int));
	}
	for (int i = 0; i < cp.N; i++) {
		for (int j = 0; j < cp.N; j++) {
			zn_1 = i;
			zn_2 = j;
			ans[j][i] = pow(-1, zn_1 + zn_2)*(float)Minor(cp, i, j) / det(cp.elm, cp.N);
		}
	}
	for (int i = 0; i < cp.N; i++) {
		for (int j = 0; j < cp.N; j++) {
			printf("\t%f\t", ans[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void umn(struct matr cp, struct matr cpp) {
	if (cp.N == cpp.M) {
		int **pt = (int **)malloc(cp.N * sizeof(int *));
		for (int i = 0; i < cp.N; i++) {
			pt[i] = (int *)malloc(cpp.M * sizeof(int));
		}
		printf("\n\t\ Production of matrices:\n");
		for (int i = 0; i < cp.N; i++) {
			for (int j = 0; j < cpp.M; j++) {
				pt[i][j] = 0;
				for (int k = 0; k < cpp.N; k++) {
					pt[i][j] += (int)cp.elm[i][k] * cpp.elm[k][j];
				}
				printf("\t%d\t", pt[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\nCan't multiply matrices");
}

void sum(struct matr cp, struct matr cpp) {
	if ((cp.N == cpp.N) && (cp.M == cpp.M)) {
		int **summ = (int **)malloc(cp.N * sizeof(int *));
		for (int i = 0; i < cp.N; i++) {
			summ[i] = (int *)malloc(cpp.M * sizeof(int));
		}
		printf("\n\t\Sum matr:\n");
		for (int i = 0; i < cp.N; ++i) {
			for (int j = 0; j < cp.M; j++) {
				summ[i][j] = cp.elm[i][j] + cpp.elm[i][j];
				printf("\t%d\t", summ[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\nCan't sum mart.");
}

int main() {
	struct matr cp;
	printf("incert the size matr A:\n");
	printf("string = ");
	scanf_s("%d", &cp.N);
	printf("column = ");
	scanf_s("%d", &cp.M);
	cp.elm = (int **)malloc(cp.N * sizeof(int *));
	for (int i = 0; i < cp.N; i++) {
		cp.elm[i] = (int *)malloc(cp.M * sizeof(int));
	}
	for (int i = 0; i < cp.N; i++) {
		for (int j = 0; j < cp.M; j++) {
			cp.elm[i][j] = rand() % 10;
		}
	}
	arrayprint(cp);
	struct matr cpp;
	printf("incert the size matr B:\n");
	printf("string = ");
	scanf_s("%d", &cpp.N);
	printf("column = ");
	scanf_s("%d", &cpp.M);
	cpp.elm = (int **)malloc(cpp.N * sizeof(int *));
	for (int i = 0; i < cpp.N; i++) {
		cpp.elm[i] = (int *)malloc(cpp.M * sizeof(int));
	}
	for (int i = 0; i < cpp.N; i++) {
		for (int j = 0; j <
			cpp.M; j++) {
			cpp.elm[i][j] = rand() % 20;
		}
	}

	arrayprint(cpp);
	if (cp.N == cp.M) {
		printf("detA = %d\n", det(cp.elm, cp.N));
		if (det(cp.elm, cp.N) != 0) {
			printf("\t\tInverese matr A:\n");
			inv(cp);
		}
		else
			printf("The inveresed matr A doen't exist.");
	}
	else
		printf("\nDet_A doen't exist");
	if (cpp.N == cpp.M) {
		printf("det_B = %d\n", det(cpp.elm, cpp.N));
		if (det(cpp.elm, cpp.N) != 0) {
			printf("\t\t inveresed matr_B:\n");
			inv(cpp);
		}
		else
			printf("inveresed matr_B doen't exist.");
	}
	else
		printf("\nDet_B doen't exist");

	umn(cp, cpp);
	sum(cp, cpp);
	arrayfree(cpp);
	arrayfree(cp);
	system("pause");
	return 0;
}