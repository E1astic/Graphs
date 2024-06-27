#include"Graph.h"


int main()
{
	int n = 5;
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
		}
	}



	Graph graph(arr,n);
	
	bool** warsh = graph.Warshall();
	graph.printMatr(warsh);
	cout << '\n';
	int** floyd = graph.Floyd();
	graph.printMatr(floyd);

	/*for (int i = 0; i < prim.size(); ++i)
	{
		cout << prim[i].first<<' ' << prim[i].second<<'\n';
	}*/
	

	cin.get();
	return 0;
}