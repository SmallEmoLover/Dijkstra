/*  ������������ �2
	�������� ��������
	������� �.�.
	���-13��		*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Dijkstra.h"

int safe_input()
{
	int n;
	if (scanf("%d", &n) != 1)
	{
		printf("\n������ �����\n");
		system("pause");
		exit(1);
	}
	if (n < 0)
	{
		printf("\n�� ����� ������������e �����\n");
		system("pause");
		exit(1);
	}
	return n;
}

void main()
{
	setlocale(LC_ALL, "RUS");

	int size;

	printf("������� ���������� ������: ");
	size = safe_input();
	if (size == 0)
	{
		printf("\n������ ����� �� ����� ���� ����� ����\n");
		system("pause");
		return;
	}
	int **graph = malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
	{
		graph[i] = malloc(sizeof(int) * size);
		for (int j = 0; j < size; j++)
			graph[i][j] = 0;
	}

	printf("������� ������� ��������� ���� ������� ���������:\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			graph[i][j] = safe_input();
			graph[j][i] = graph[i][j];
		}
	}

	int node;
	printf("������� ��������� �������: ");
	node = safe_input();
	if (node == 0 || node > size)
	{
		printf("\n������������ �������\n");
		system("pause");
		return;
	}

	int **distances = Dijkstra(graph, node, size);

	for (int i = 0; i < size; i++)
		printf("���������� �� %d-� ������� = %d\n", i + 1, distances[i]);

	free(distances);

	system("pause");
}