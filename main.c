#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>





int main() {
	int** s = NULL;
	int row = 0, column = 0;
	int rez = read("C:\\Users\\nabyn\\OneDrive\\Рабочий стол\\информатика\\2 семестр\\ЛАБА2\\лаба2.1\\input.txt", s, row, column);
	if (rez == -1)
		return -1;
	 sort_snake("C:\\Users\\nabyn\\OneDrive\\Рабочий стол\\информатика\\2 семестр\\ЛАБА2\\лаба2.1\\input.txt", s, row, column);
	
	return 0;
}
