#include<iostream>
#include<vector>
#include<queue>

using namespace std;

enum colortype{BLACK,WHITE,GREY};

vector<int> BFS(vector<vector<int>> alist, int start) {
	
	int lsize = alist.size();
	vector<int>dist(lsize, 0);//distance set to zero
	int u;//temp value 
	vector<enum colortype>color(lsize, WHITE);//set all node to white
	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		u = que.front();
		que.pop();
		for (int i = 0; i < alist[u].size(); i++)
		{
			int v = alist[u][i];
			if (color[v] == WHITE) {
				color[v] = GREY;//visited
				que.push(v);
				dist[v] = dist[u] + 1;
			}
		}
		color[u] = BLACK;
	}
	return dist;
}
int main() {
	int employe, countfrd,testcase,start, frds, M, D;
	cin >> employe;
	vector<vector<int>> adjlist(employe);
	for (int i = 0; i < employe; i++)
	{
		cin >> countfrd;
		for (int j = 0; j < countfrd; j++)
		{
			cin >> frds;
			adjlist[i].push_back(frds);
		}
	}
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin >> start;
		if (adjlist[start].size() > 0) {
			vector<int> d = BFS(adjlist, start);
			int height = -1;
			for (int j = 0; j < d.size(); j++)
			{
				//cout << d[j] << endl;
				if (d[j] > height)height = d[j];
			}
			vector<int> freq(height + 1, 0);
			for (int k = 0; k < d.size(); k++)
			{
				freq[d[k]]++;
			}
			M = -1;
			for (int l = 1; l < freq.size(); l++)
			{
				if (M < freq[l]) {
					M = freq[l];
					D = l;
				}
			}
			cout << M << " " << D << endl;
		}
		else
			cout << "0" << endl;
	}	
	return 0;
}