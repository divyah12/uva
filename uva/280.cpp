#include<iostream>
#include<vector>
#include<queue>
#define endl '\n'

using namespace std;
enum colr {white,grey};
vector<enum colr> color;

void unvisited(vector<vector<int>>graph,int src) {
	//dfs	
	for (int i = 0; i<graph[src].size(); i++) {
		int cur_ver = graph[src][i];
		if (color[cur_ver]==white)
		{
			color[cur_ver] = grey;
			unvisited(graph,cur_ver);
		}
	}
}

int main() {
	int n,v1, v2, num, src;
	while (cin >> n && n != 0) {
		vector<vector<int>>graph(n);
		//color.resize(n,white);
		while (cin >> v1 && v1!=0) {//vertex1
			while (cin >> v2 && v2 != 0) {//list of 2nd edge vertex 
				graph[v1 - 1].push_back(v2 - 1);
			}
		}
		cin >> num;//num of times loop runs

		for (int i = 0; i < num; i++) {
			color.assign(n, white);
			cin >> src;
			int count = 0;
			int temp = src - 1;
			unvisited(graph,src - 1);
			vector<int>result;
			for (int i = 0; i < color.size(); i++)
			{
				if (color[i] == white) {
					count++;
					result.push_back(i + 1);
				}
			}
			cout << count;
			for (int i = 0; i <result.size(); i++)
			{
				cout << " " << result[i];
			}
			cout << endl;
		}
	}

	return 0;
}