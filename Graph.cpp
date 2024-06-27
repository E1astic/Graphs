#include"Graph.h"

Graph::Graph(int** _arr, int _size)
{
	size = _size;
	arr = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			arr[i][j] = _arr[i][j];
		}
	}
}

//		======DFS=====
void Graph::dfs(bool*& mark, int cur)
{
	mark[cur] = 1;
	cout << cur << ' ';
	for (int j = 0; j < size; ++j)
	{
		if (arr[cur][j] == 1 && mark[j] == 0)
			dfs(mark, j);
	}
}

void Graph::DFS()
{
	bool* mark = new bool[size] {0};
	for (int i = 0; i < size; ++i)
	{
		if (mark[i] == 0)
			dfs(mark, i);
	}

}

//		======BFS=====
void Graph::bfs(bool*& mark, int ind)
{
	mark[ind] = 1;
	queue<int>q;
	q.push(ind);
	while (!q.empty())
	{
		int cur = q.front();
		for (int j = 0; j < size; ++j)
		{
			if (arr[ind][j] == 1 && mark[j] == 0)
			{
				q.push(j);
				mark[j] = 1;
			}
		}
		cout << cur << ' ';
		q.pop();
	}
}

void Graph::BFS()
{
	bool* mark = new bool[size] {0};
	for (int i = 0; i < size; ++i)
	{
		if (mark[i] == 0)
			bfs(mark, i);
	}
}


//	======Транзитиное замыкание=====
bool** Graph::Warshall()
{
	bool** warsh = new bool* [size];
	for (int i = 0; i < size; ++i)
	{
		warsh[i] = new bool[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j] == 0)
				warsh[i][j] = 0;
			else
				warsh[i][j] = 1;
		}
	}

	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (i != j)
					warsh[i][j] = (warsh[i][k] && warsh[k][j]) || warsh[i][j];
			}
		}
	}
	return warsh;
}


//	======Минимальные пути из каждой точки в каждую=====
int** Graph::Floyd()
{
	int** floyd = new int* [size];
	for (int i = 0; i < size; ++i)
		floyd[i] = new int[size];

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			floyd[i][j] = arr[i][j];
		}
	}
	cout << '\n';

	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (floyd[i][k] != 0 && floyd[k][j] != 0 && i != j)   // если путь через вершину k существует,  и "i != j" чтобы i -> j = 0
				{
					if (floyd[i][j] == 0)
						floyd[i][j] = floyd[i][k] + floyd[k][j];
					else
						floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}
			}
		}
	}
	return floyd;
}


//	======Массив рёбер графа, имеющих минимальные длины и соединяющих все точки графа=====

vector<pair<int, int>> Graph::Prim()
{
	vector<pair<int, int>> ways;		// рёбра
	vector<int>points;					// точки в остове
	bool* mark = new bool[size] {0};
	int sum = 0;

	points.push_back(0);
	mark[0] = 1;
	while (ways.size() < size - 1)
	{
		int from;
		int to;
		int min = 1e9;

		for (int k = 0; k < points.size(); ++k)  // проходим по всем точкам в остове
		{
			for (int j = 0; j < size; ++j)
			{
				if (arr[points[k]][j] != 0 && mark[j] == 0 && arr[points[k]][j] < min)  //ищем минимальный путь, ведущий из точки остова в точку, которой еще нет в остове
				{
					min = arr[points[k]][j];
					from = points[k];
					to = j;
				}
			}
		}
		sum += min;		//возможен вариант с return sum (минимальной суммой дорог, соединяющих все пути)
		ways.push_back({ from,to });
		points.push_back(to);
		mark[to] = 1;
	}
	
	return ways;
}



void Graph::printMatr()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void Graph::printMatr(bool** arr)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void Graph::printMatr(int** arr)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
