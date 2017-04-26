#include <iostream>
#include<limits>
#include<vector>
#include<set>
#define endl '\n'

using namespace std;

void dijkstra( vector<vector<pair<int,int>>> graph,int start) {

	set<pair<int, int> > set_q;	
	
	vector<int> dist(graph.size(),INT_MAX);
	int u, v, d;	
	dist[start] = 0;
	set_q.insert(make_pair(0, start));

	while (!set_q.empty())
	{
		d = set_q.begin()->first;
		u = set_q.begin()->second;
		set_q.erase(set_q.begin());
		//visiting the next edge

		for (vector<pair<int, int> > ::iterator i = graph[u].begin(); i != graph[u].end(); i++)
		{
			v = i->first;
			int temp_weight = i->second;
			int weight =temp_weight+ d;
			//Relax edge with dist
			if (weight<dist[v])
			{
				set_q.erase(make_pair(dist[v], v));
				dist[v] = weight;
				set_q.insert(make_pair(dist[v], v));
			}
		}
	}
	for (int i = 0; i <dist.size(); i++)
	{
		cout << i<<"  :"<<dist[i] << endl;
	}
}

int main() {
	
	int casenum;
	cin >> casenum;//number of case
	while (casenum--)
	{
		int n, m;
		cin >> n;//row
		cin >> m;//colum
		vector<vector<int>> maze(n,vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{//write val directly to matrix
				cin >>maze[i][j];
			}
		}
		vector<vector<pair<int, int>>> graph(n*m);
		int node=0;
		//converting from matrix data to graph 
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < m-1; j++)
			{
				//cout << "node  " << node << endl;
				//maze[i][j] holds the weight of the edge
				graph[node].push_back(make_pair(j+1,maze[i][j+1]));//next node 
				graph[j+1].push_back(make_pair(node, maze[i][j + 1]));//undirectional
				graph[(((i + 1)*n) + j)].push_back(make_pair(node, maze[i+1][j]));//undirectional
				graph[node].push_back(make_pair((((i+1)*n)+j), maze[i+1][j]));//below node
				node++;
			}node++;
		}
		//last row - matrix data to graph
		for (int i = 0; i <n-1; i++)
		{
			//cout << "node  " << ((i + 1)*m) - 1 << endl;
			graph[((i+1)*m)-1].push_back(make_pair(((i+2)*m)-1, maze[i+1][m-1]));//below node
			graph[((i + 2)*m) - 1].push_back(make_pair(((i + 1)*m) - 1, maze[i + 1][m - 1]));//undirectional
		}
		//last colum - matrix data to graph
		node = (n - 1)*m;
		for (int i = 0; i <m - 1; i++)
		{
			//cout << "node  " << node << endl;
			graph[node].push_back(make_pair(node+1, maze[n-1][i+ 1]));//below node
			graph[node+1].push_back(make_pair(node, maze[n - 1][i + 1]));//undirectional
			node++;
		}
	
		dijkstra(graph, 0);
	}
	return 0;
}