#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <queue>
using namespace std;

void bfs(int v, int* dist, int n, int** matr) {
	queue <int> q;
	q = {};
	q.push(v);
	dist[v] = 0;
	while (q.size() != 0) {
		v = q.front();
		q.pop();
		printf("%d \t", v + 1);
		for (int i = 0; i < n; i++) {
			if (matr[v][i] == 1 && dist[i] == -1) {
				q.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}

}



int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n = 0;
	printf("Введите количество вершин: ");
	scanf_s("%d", &n);
	int** matr1 = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matr1[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr1[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			matr1[i][j] = rand() % 2;
			matr1[j][i] = matr1[i][j];
			if (i == j)
				matr1[i][j] = 0;
		}

	}


	printf("\n   Матрица M1:    \n№  ");
	for (int i = 0; i < n; i++) {
		printf(" %d", i + 1);
	}
	printf("\n__|");
	for (int i = 0; i < n; i++) {
		printf("__");
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		{
			printf("%d | ", i + 1);
			for (int j = 0; j < n; ++j)
				printf("%d ", matr1[i][j]);
			printf("\n");
		}
	}

	int ver = 0, op = 0;
	while (1) {
		printf("\nВведите номер операции:\n1)Выбрать вершину для обхода 2)Выйти\n");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
		{
			int* dist = (int*)malloc(sizeof(int) * n);
			for (int i = 0; i < n; i++)
				dist[i] = -1;

			printf("Выберите вершину, с которой начинать обход:");
			scanf_s("%d", &ver);
			if (ver <= n && ver > 0) {
				ver -= 1;
				printf("Обход в ширину: \n");
				bfs(ver, dist, n, matr1);
				printf("\n\nРасстояния от указанной вершины\n\n");
				for (int i = 0; i < n; i++)
					printf("[%d] = %d\t", i + 1, dist[i]);
				free(dist);
			}
			else
				printf("Нет вершины!");


			break;
		}
		case 2:
			for (int i = 0; i < n; i++) {
				free(matr1[i]);
			}
			free(matr1);

			return 0;
		}
	}

}