#include <iostream>
using namespace std;
int N;
int Gnode[10][2];
int Visited[100] = {};
int G[100][100];
int Queue[100];
int front = -1, rear = -1;
void Add(int j)
{
	if (rear == N + 1)
	{

	}
	else
	{
		rear = rear + 1;
		Queue[rear] = j;
	}
}
int Delete()
{
	if (front == rear)
	{

	}
	else
	{
		front = front + 1;
		return Queue[front];
	}
}
void BFS(int i)
{
	// 廣度優先搜尋，用佇列輔助
	Visited[i] = 1;
	cout << i + 1 << " ";
	for (int j = 0; j <= N - 1; j++)
	{
		if (G[i][j] == 1)
		{
			if (Visited[j] != 1)
			{
				Add(j);
			}	
		}
	}
	while (front!=rear)
	{
		i = Delete();
		if (Visited[i] != 1)
		{
			BFS(i);
		}
	}
}
int main(int argc, char *argv[])
{
	int i, E;
	int connect1, connect2;
	cin >> i >> N >> E;
	for (int j = 0; j < E; j++)
	{
		cin >> connect1 >> connect2;
		Gnode[j][0] = connect1;
		Gnode[j][1] = connect2;
	}
	int R_node;
	for (int row = 0; row <= N - 1; row++)
	{
		for (int column = 0; column <= N - 1; column++)
		{
			G[row][column] = 0;
		}
	}
	for (int row = 0; row <= E - 1; row++)
	{
		R_node = Gnode[row][0] - 1;
		for (int column = 0; column <= 1; column++)
		{
			G[R_node][Gnode[row][column] - 1] = 1;
		}
	}
	for (int row = 0; row <= N - 1; row++)
	{
		for (int column = 0; column <= N - 1; column++)
		{
			if (row == column)
				G[row][column] = 0;
		}
	}
	for (int row = 0; row <= E - 1; row++)
	{
		R_node = Gnode[row][1] - 1;
		for (int column = 0; column <= 1; column++)
		{
			G[R_node][Gnode[row][column] - 1] = 1;
		}
	}
	BFS(i-1);
}
