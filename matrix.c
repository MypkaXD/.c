#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
	system("chcp 1251");
	system("cls");

	int f = 20;// максимальный размер матрицы

	int N;
	printf("Введите кол-во строк-N матрицы-A: ");
	scanf_s("%d", &N);
	if (N > f || N <= 0) {
		printf("ERROR: Вы ввели неправильное значение N \n");
		return 0;
	}

	int M;
	printf("Введите кол-во столбцов-M матрицы-A: ");
	scanf_s("%d", &M);
	if (M > f || M <= 0) {
		printf("ERROR: Вы ввели неправильное значение M \n");
		return 0;
	}

	int** matrixA;

	matrixA = (int**)malloc(N * sizeof(int*));
	for (int count = 0; count < N; count++) {
		matrixA[count] = (int*)malloc(M * sizeof(int));
	}

	for (int count = 0; count < N; count++) {
		for (int COUNT = 0; COUNT < M; COUNT++) {
			printf("a[%d][%d] = ", count, COUNT);
			scanf_s("%d", &matrixA[count][COUNT]);
		}
	}
	printf("Матрица А:\n");
	for (int count = 0; count < N; count++) {
		for (int COUNT = 0; COUNT < M; COUNT++) {
			printf("%5d ", matrixA[count][COUNT]);
		}
		printf("\n");
	}

	printf("================================================\n");

	int* checker;

	checker = (int*)malloc(N * sizeof(int));
	for (int count = 0; count < N; count++) {
		if (M > 1) {
			for (int COUNT = 0; COUNT < M - 1; COUNT++) {
				if ((matrixA[count][COUNT] > matrixA[count][COUNT + 1]) && (matrixA[count][COUNT] % 2 != 0))
					checker[count] = count;
				else {
					checker[count] = -1;
				}
			}
		}
		else if (M == 1) {
			for (int COUNT = 0; COUNT < M; COUNT++) {
				if (matrixA[count][COUNT] % 2 != 0)
					checker[count] = count;
				else {
					checker[count] = -1;
				}
			}
		}
	}


	for (int count = 0; count < N; count++) {
		printf("%d\t", checker[count]);
	}

	int maxIndex = -1;

	for (int count = 0; count < N; count++) {
		if (checker[count] >= maxIndex) {
			maxIndex = checker[count];
		}
		else
			maxIndex = maxIndex;
	}
	printf("Инедкс строки = ");
	printf("%d", maxIndex);
	printf("\n================================================\n");

	int N2;

	if (maxIndex >= 0) {
		N2 = N - 1;
		if (N2 < 0) {
			printf("ERROR: неправильная длина матрицы");
			exit(0);
		}
	}
	else if (maxIndex == -1) {
		N2 = N;
	}

	int** matrixB;

	matrixB = (int**)malloc(N2 * sizeof(int*));//Выделение памяти для матрицы В
	for (int count = 0; count < N2; count++) {
		matrixB[count] = (int*)malloc(M * sizeof(int));
	}

	for (int count = 0; count < N; count++) {//копируем элементы matrixA в матрицу B
		for (int COUNT = 0; COUNT < M; COUNT++) {
			if (maxIndex == -1) {
				matrixB[count][COUNT] = matrixA[count][COUNT];
			}
			else {
				if (maxIndex == count) {
					continue;
				}
				else if (count < maxIndex) {
					matrixB[count][COUNT] = matrixA[count][COUNT];
				}
				else if (count > maxIndex) {
					matrixB[count - 1][COUNT] = matrixA[count][COUNT];
				}
			}
		}
	}


	printf("Матрица B: \n");

	for (int count = 0; count < N2; count++) {//печатаем matrixB
		for (int COUNT = 0; COUNT < M; COUNT++) {
			printf("%5d ", matrixB[count][COUNT]);
		}
		printf("\n");
	}


	for (int count = 0; count < N2; count++)//удаление массива matrixB
		free(matrixB[count]);
	free(matrixB);

	for (int count = 0; count < N; count++)//удаление массива matrixA
		free(matrixA[count]);
	free(matrixA);

	free(checker);//удаление массива matrixChecker

	return 0;
}
