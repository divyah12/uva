#include<iostream>
#include<vector>
#include<queue>

using namespace std;

enum colortype { BLACK, WHITE, RED };

void BFS(vector<vector<int>> alist, int start) {
	
	enum colortype current;//holds the next color to be changed
	bool res =true;//same colored neighbour
	
	vector<enum colortype>color;
	color.resize(alist.size(), WHITE);//set all node to white
	color[start] = BLACK;//start node
	
	queue<int> que;
	que.push(start);

	while (!que.empty() && res)
	{
		int u = que.front();
		que.pop();
		//if-then-else
		//flip color and save to current
		current = (color[u] == BLACK) ? RED : BLACK;
		for (int i = 0; i < alist[u].size(); i++)
		{
			int v = alist[u][i];
			if (color[v] == WHITE) {
				//unvisited
				que.push(v);
				//push the node and make it visited
				color[v] = current;				
			}
			else {
				//visited but has same colored neighbour
				if (color[u] == color[v]) {
					res = false;
					break;
				}
			}
		}
	}
	if(!res)
		cout << "NOT BICOLORABLE." << endl;
	else
		cout << "BICOLORABLE." << endl;
}
int main() {
	int n, e;

	//cin >> n;//num of nodes(0to n-1)
	while (cin >> n && n != 0) {

		cin >> e;//num of edges in the graph
			vector<vector<int>> graph;
			graph.resize(n);
			//cout << n << " n l " << l << endl;
			for (int i = 0; i < e; i++) {
				int a, b;
				cin >> a >> b;//read the nodes of the edge
							  //cout << a << "  ab  " << b << endl;
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
			BFS(graph, 0);
			graph.clear();
	}
return 0;
}