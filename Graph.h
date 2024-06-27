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
	
	void DFS();						//� �������
	void BFS();						//� ������
	bool** Warshall();				//������������ ���������
	int** Floyd();					//���������� ���� �� ������ ������� � ������
	vector<pair<int, int>> Prim();	//����������� ����� (����������� ����, ����������� ��� �����)
	

	void printMatr();
	void printMatr(bool**);
	void printMatr(int**);
};