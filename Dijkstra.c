/*  Àëãîðèòì Äåéêñòðû
	Êóëàêîâ Ä.Ñ.
	ÈÂÒ-13ÁÎ		*/

#include <stdlib.h>

int* Dijkstra(int** graph, int node, int size)
{
	node--;
	//Комментарий для Насти
	int *distance = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		distance[i] = 0;
	distance[node] = 0;

	int *passed_nodes = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		passed_nodes[i] = 1;

	int min_node = node;
	int min_distance;

	while (1)
	{
		min_distance = 0;
		for (int i = 0; i < size; i++)
		{
			if (passed_nodes[i] == 0)
				continue;

			if (graph[node][i] != 0 &&
				(distance[node] + graph[node][i] < distance[i] || distance[i] == 0))
				distance[i] = distance[node] + graph[node][i];
		}
		passed_nodes[node] = 0;
		for (int i = 0; i < size; i++)
		{
			if (passed_nodes[i] == 0)
				continue;

			if (distance[i] != 0 && (min_distance == 0 || distance[i] < min_distance))
			{
				min_distance = distance[i];
				min_node = i;
			}
		}

		if (min_node == node)
			break;
		node = min_node;
	}

	free(passed_nodes);

	return(distance);
}