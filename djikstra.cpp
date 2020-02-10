#include <stdio.h>

struct tdata
{
	int cost;
	int node;
};

tdata heap[100];
int count = 0;

int compare(tdata a, tdata b)
{
	if(a.cost < b.cost)
		return -1;
	else if(a.cost > b.cost)
		return 1;
	else
	{
		if(a.node < b.node)
			return -1;
		else if(a.node> b.node)
			return 1;
		else
			return 0;
	}
}

void heapDown(int idx)
{
	int curIdx = idx;
	tdata curVal = heap[curIdx];

	//check if current node is larger than left node
	if(2*idx <= count && compare(heap[2*idx], heap[curIdx]) < 0)
	{
		curIdx = 2*idx;
		curVal = heap[curIdx];
	}

	//check if current node is larger than right node
	if(2*idx+1 <= count && compare(heap[2*idx+1], heap[curIdx]) < 0)
	{
		curIdx = 2*idx+1;
		curVal = heap[curIdx];
	}

	if(curIdx == idx)
		return;

	tdata temp = heap[curIdx];
	heap[curIdx] = heap[idx];
	heap[idx] = temp;

	heapDown(curIdx);
}

void insert(int cost, int node)
{
	if(count>=100)
	{
		printf("Heap is already full!\n");
		return;
	}

	count++;
	heap[count].cost = cost;
	heap[count].node = node;

	//heap up
	int idx = count;
	while(idx > 1 && compare(heap[idx/2], heap[idx]) > 0)
	{
		tdata temp = heap[idx/2];
		heap[idx/2] = heap[idx];
		heap[idx] = temp;

		idx /= 2;
	}
}

tdata extractMin()
{
	if(count == 0)
	{
		printf("Nothing to extract!\n");
		tdata retVal;
		retVal.cost = 1<<30;
		retVal.node = -1;
		return retVal;
	}

	if(count == 1)
	{
		count--;
		return heap[1];
	}

	tdata retVal = heap[1];
	heap[1] = heap[count];
	count--;

	//heap down
	heapDown(1);

	return retVal;
}


int adjMatrix[100][100];
int visited[100];
int distance[100];
int nodeCount;
int previous[100];

int djikstra(int from, int to)
{
	for(int i=0;i<100;i++)
	{
		visited[i] = 0;
		distance[i] = 1<<30;
		previous[i] = -1;
	}

	distance[from] = 0;
	insert(0, from);

	//for(int i=0;i<nodeCount;i++)
	while(count > 0)
	{
		//find non-visited node with minimum cost
		/*
		int idx = -1;
		for(int k=0; k<nodeCount; k++)
		{
			if(visited[k] == 0)
			{
				if(idx == -1)
					idx = k;
				else if(distance[k] < distance[idx])
					idx = k;
			}
		}*/
		
		tdata currNode = extractMin();
		int idx = currNode.node;

		//visit node idx
		visited[idx] = 1;
		for(int k=0; k<nodeCount; k++)
		{
			if(adjMatrix[idx][k] > 0)
			{
				if(distance[idx] + adjMatrix[idx][k] < distance[k])
				{
					distance[k] = distance[idx] + adjMatrix[idx][k];
					insert(distance[k], k);
					previous[k] = idx;
				}
			}
		}
	}

	return distance[to];
}

void tracePath(int idx)
{
	if(previous[idx] == -1)
	{
		printf("%d ", idx);
		return;
	}

	tracePath(previous[idx]);
	printf("%d ", idx);
}

void main()
{
	for(int i=0;i<100;i++)
		for(int k=0;k<100;k++)
			adjMatrix[i][k] = 0;

	adjMatrix[0][1] = 5;
	adjMatrix[0][2] = 3;
	adjMatrix[1][3] = 4;
	adjMatrix[2][3] = 3;
	adjMatrix[1][4] = 7;
	adjMatrix[2][4] = 10;
	adjMatrix[3][4] = 5;

	nodeCount = 5;

	int cost = djikstra(0,4);
	printf("cost = %d\n", cost);

	tracePath(4);

	getchar();
}