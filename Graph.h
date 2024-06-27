#pragma once
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph
{
	int** arr;
	int size;

	void dfs(bool*& mark, int cur);
	void bfs(bool*& mark, int cur);
	
public:
	Graph(int** _arr, int _size);
	
	void DFS();						//в глубину
	void BFS();						//в ширину
	bool** Warshall();				//транзитивное замыкание
	int** Floyd();					//кратчайшие пути из каждой вершины в каждую
	vector<pair<int, int>> Prim();	//минимальный остов (минимальный путь, соединяющий все точки)
	

	void printMatr();
	void printMatr(bool**);
	void printMatr(int**);
};