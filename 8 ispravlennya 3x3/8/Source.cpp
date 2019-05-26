#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h" 
#include "math.h" 
#include "stdlib.h" 

int det(int data[3][3]) {
	int str1, str2, str3;
	int det;
	str1 = data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2]);
	str2 = data[1][0] * (data[0][1] * data[2][2] - data[0][2] * data[2][1]);
	str3 = data[2][0] * (data[0][1] * data[1][2] - data[1][1] * data[0][2]);
	det = str1 - str2 + str3;
	return det;
}
void umn(int data[3][3], int dota2[3][3]) {
	int umn[3][3];
	FILE*fp = fopen("umn.txt", "r+");
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			umn[i][j]=data[i][j]* dota2[0][j] + data[i][1] * dota2[1][j] + data[i][2] * dota2[2][j];
		}
	}
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			printf("\t%d\t", umn[i][j]);
			fprintf(fp, "%d\t", umn[i][j]);
		}
		fprintf(fp, "\n");
		printf("\n");
	}
	fclose(fp);
}
void sum(int data[3][3], int dota2[3][3]) {
	int sum[3][3];
	FILE* fp = fopen("sum.txt", "r+");
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			sum[i][j] = data[i][j] + dota2[i][j];
		}
	}
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			printf("\t%d", sum[i][j]);
			fprintf(fp, "%d\t", sum[i][j]);
		}
		printf("\n");
		fprintf(fp, "\n");
	}
	fclose(fp);
}
void inverse(int K, int det, int data[3][3]) {
	float inv[3][3];
	if (K == 1) {
		FILE* fp = fopen("inv1.txt", "r+");
		for (int i = 0; i <= 2; i++) {
			int i1 = (i + 1) % 3;
			int i2 = (i + 2) % 3;
			for (int j = 0; j <= 2; j++) {
				int j1 = (j + 1) % 3;
				int j2 = (j + 2) % 3;
				inv[j][i] = (float)(data[i1][j1] * data[i2][j2] - data[i1][j2] * data[i2][j1]) / det;
			}
			printf("\n");
		}
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				printf("\t%f", inv[i][j]);
				fprintf(fp, "%f\t", inv[i][j]);
			}
			fprintf(fp, "\n");
			printf("\n");
		}
		fclose(fp);
	}
	else
		if (K == 2) {
			FILE* fp = fopen("inv2.txt", "r+");
			for (int i = 0; i <= 2; i++) {
				int i1 = (i + 1) % 3;
				int i2 = (i + 2) % 3;
				for (int j = 0; j <= 2; j++) {
					int j1 = (j + 1) % 3;
					int j2 = (j + 2) % 3;
					inv[j][i] = (float)(data[i1][j1] * data[i2][j2] - data[i1][j2] * data[i2][j1]) / det;
				}
			}
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					printf("\t%f", inv[i][j]);
					fprintf(fp, "%f\t", inv[i][j]);
				}
				printf("\n");
				fprintf(fp, "\n");
			}
			fclose(fp);
		}
}

int main() {
	int data[3][3], dota2[3][3];
	int det_1 = 0, det_2 = 0;
	int a;
	printf("keyboard text 1\n text from file 2\n");
	scanf_s("%d", &a);
	if (a == 1) {
		printf("insert data:\n");
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				printf("data[%d][%d] = ", i, j);
				scanf_s("%d", &data[i][j]);
			}
		}
		printf("incert dota2:\n");
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				printf("dota2[%d][%d] = ", i, j);
				scanf_s("%d", &dota2[i][j]);
			}
		}
		printf("Your matr:\n");
		printf("1st:\n");
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				printf("\t%d", data[i][j]);
			}
			printf("\n");
		}
		printf("2nd:\n");
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				printf("\t%d", dota2[i][j]);
			}
			printf("\n");
		}
		det_1 = det(data);
		det_2 = det(dota2);
		FILE* fp = fopen("det.txt", "r+");
		fprintf(fp, "det_1 = %d\tdet_2 = %d", det_1, det_2);
		fclose(fp);
		printf("\nDet_1 = %d Det_2 = %d\n", det_1, det_2);
		printf("\nwhy find the inverse?\n");
		int K;
		printf("If you want only 1st inversed write 1:\nIf only 2nd inversed write 2:\nIf you want both write 3:\n");
		scanf_s("%d", &K);
		if (K == 1) {
			if (det_1 == 0) {
				printf("doesn't exist.\n");
			}
			else
				if (det_1 != 0) {

					printf("Inversed matr:\n");
					inverse(K, det_1,data);
				}
		}
		else
			if (K == 2) {
				if (det_2 == 0) {
					printf("doesn't exist.\n");
				}
				else
					if (det_2 != 0) {
						printf("Inversed matr:\n");
						inverse(K ,det_2,dota2);
					}
			}
			else
				if (K == 3) {

					if (det_1 == 0) {
						printf("doesn't exist.\n");
					}
					else
						if (det_1 != 0) {
							int k = 1;
							printf("Inversed matr_1:\n");
							inverse(K,det_2,dota2);
						}
					if (det_2 == 0) {
						printf("doesn't exist.\n");
					}
					else
						if (det_2 != 0) {
							int k = 2;
							printf("Inversed matr_2:\n");
							inverse(K,det_2,dota2);
						}
				}
		printf("\nSum of matr:\n");
		sum(dota2, data);
		printf("\nUmn matr:\n");
		umn(dota2, data);
	}
	else
		if (a == 2) {
			int element;
			FILE* f_mat1 = fopen("matrix_1.txt", "rt");
			FILE* f_mat2 = fopen("matrix_2.txt", "rt");
			if (f_mat1 == NULL || f_mat2 == NULL)
			{
				printf("Error!");
				return 0;
			}
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					fscanf(f_mat1, "%d", &element);
					data[i][j] = element;
				}
			}
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					fscanf(f_mat2, "%d", &element);
					dota2[i][j] = element;
				}
			}
			printf("Your matr:\n");
			printf("\nThe first matr:\n");
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					printf("\t%d", data[i][j]);

				}
				printf("\n");
			}
			printf("The second matr:\n");
			for (int i = 0; i <= 2; i++) {
				for (int j = 0; j <= 2; j++) {
					printf("\t%d", dota2[i][j]);
				}
				printf("\n");
			}
			fclose(f_mat1);
			fclose(f_mat2);
			det_1 = det(data);
			det_2 = det(dota2);
			printf("\nDet1 = %d Det2 = %d\n", det_1, det_2);
			FILE* fp = fopen("det.txt", "r+");
			fprintf(fp, "det1 = %d\tdet2 = %d", det_1, det_2);
			fclose(fp);
			printf("\nwhy find the inverse?\n");
			int K;
			printf("If you want only 1st inversed write 1:\nIf only 2nd inversed write 2:\nIf you want both write 3:\n");
			scanf_s("%d", &K);
			if (K == 1) {
				if (det_1 == 0) {
					printf("doesn't exist.\n");
				}
				else
					if (det_1 != 0) {
						printf("Inversed matr:");
						inverse(K,det_1,data);
					}
			}
			else
				if (K == 2) {
					if (det_2 == 0) {
						printf("doesn't exist.\n");
					}
					else
						if (det_2 != 0) {
							printf("Inversed matr:\n");
							inverse(K,det_2, dota2);
						}
				}
				else
					if (K == 3) {

						if (det_1 == 0) {
							printf("doesn't exist.\n");
						}
						else
							if (det_1 != 0) {
								int K = 1;
								printf("Inversed matr_1:");
								inverse(K,det_1, data);
							}
						if (det_2 == 0) {
							printf("doesn't exist.\n");
						}
						else
							if (det_2 != 0) {
								int k = 2;
								printf("Inversed matr 2:\n");
								inverse(K,det_2, dota2);
							}
					}
			printf("\nSum of matr:\n");
			sum(dota2, data);
			printf("\nUmn of matr:\n");
			umn(dota2, data);
		}
		system("pause");
		return 0;
}