#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void out(const char* a, int** s, int row, int column) {
	FILE* f;
	f = fopen(a, "w");
	if (f == NULL) {
		puts("Open file error");
		return;
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				fprintf(f, "%d", s[i][j]);
				if (j != column - 1)
					fprintf(f, "C:\\Users\\nabyn\\OneDrive\\Рабочий стол\\информатика\\2 семестр\\ЛАБА2\\лаба2.1\\input.txt ");
			}
			if (i != row - 1)
				fprintf(f, "\n");
		}
		fclose(f);
	}
}

int read(const char* a, int** s, int row, int column) {
	FILE* f;
	f = fopen(a, "rt");
	if (f == NULL) {
		puts("Open file error");
		return -1;
	}
	else {

		if (fscanf(f, "%d", &row) == 0)
			return -1;
		if (fscanf(f, "%d", &column) == 0)
			return -1;
		printf("%d\n", row);
		printf("%d\n", column);

		int i;
		s = (int**)realloc(s, sizeof(int*) * row);
		if (s == NULL)
			return -1;
		for (i = 0; i < row; i++)
			s[i] = NULL;
		for (i = 0; i < row; i++) {
			s[i] = (int*)realloc(s[i], column * sizeof(int));
			if (s[i] == NULL)
				return -1;
		}


		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (fscanf(f, "%d", &s[i][j]) == 0)
					return -1;
			}
		}
		fclose(f);

	}
	return 0;
}

int* ind(int ii, int n, int** matr) {
	int* iP = matr[ii / n];
	int j = ii % n;
	j = (ii / n) & 1 ? n - j - 1 : j;// проверка четности нечетности (с конца если четный)
	return iP + j;
}

void sort_snake(const char* a, int** s, int row, int column) {
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < row * column - 1; i++) {
			int* i1 = ind(i, column, s);
			int* i2 = ind(i + 1, column, s);
			if (*i1 > *i2) {
				flag = 1;
				int k = *i2;
				*i2 = *i1;
				*i1 = k;
			}
		}
	}
	out(a, s, row, column);
}