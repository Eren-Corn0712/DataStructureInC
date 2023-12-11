#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void* create2DArray(int rows, int cols, int dataType) {
	if (dataType == 1) { // 整数类型
		int** arr = (int**)malloc(rows * sizeof(int*));
		for (int i = 0; i < rows; i++) {
			arr[i] = (int*)malloc(cols * sizeof(int));
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				arr[i][j] = 0;
			}
		}


		return (void*)arr;
	}
	else if (dataType == 2) { // 字符类型
		char** arr = (char**)malloc(rows * sizeof(char*));
		for (int i = 0; i < rows; i++) {
			arr[i] = (char*)malloc(cols * sizeof(char));
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				arr[i][j] = 'x';
			}
		}
		return (void*)arr;
	}
	else {
		return NULL;
	}
}

void* printf2DArray(void* arr, int rows, int cols, int dataType)
{
	if (dataType == 1)
	{
		int** temp_arr = (int**)arr;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				printf("%d ", temp_arr[i][j]);
			}
			printf("\n");
		}
	}
	return NULL;
}

