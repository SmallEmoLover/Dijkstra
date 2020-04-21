/*  Лабораторная №2
	Алгоритм Дейкстры
	Кулаков Д.С.
	ИВТ-13БО		*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Dijkstra.h"

//контроль ввода
int safe_input()
{
	int n;
	if (scanf("%d", &n) != 1)
	{
		printf("\nОшибка ввода\n");
		system("pause");
		exit(1);
	}
	if (n < 0)
	{
		printf("\nВы ввели отрицательноe число\n");
		system("pause");
		exit(1);
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int size;
	printf("Введите количество вершин: ");
	size = safe_input();
	if (size == 0)
	{
		printf("\nРазмер графа не может быть равен нулю\n");
		system("pause");
		return 1;
	}
	int **graph = malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
	{
		graph[i] = malloc(sizeof(int) * size);
		for (int j = 0; j < size; j++)
			graph[i][j] = 0;
	}

	printf("Введите матрицу смежности выше главной диагонали:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			graph[i][j] = safe_input();
			graph[j][i] = graph[i][j];
		}
	}

	int node;
	printf("Введите выбранную вершину: ");
	node = safe_input();
	if (node == 0 || node > size)
	{
		printf("\nНедопустимая вершина\n");
		system("pause");
		return 1;
	}

	int **distances = Dijkstra(graph, node, size);
	for (int i = 0; i < size; i++)
	{
		if (i == node)
			continue;

		if (distances[i] != 0)
			printf("Расстояние до %d-й вершины = %d\n", i + 1, distances[i]);
		else
			printf("К вершине %d нет пути\n", i);
	}

	free(distances);
	system("pause");

	return 0;
}