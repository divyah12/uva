#include <iostream>
#include<vector>
#include<set>
#define INT_MAX 2147483647 
#define endl '\n'

using namespace std;

void dijkstra(vector<vector<int>> graph, int start,int first_val,int n,int m) {

	//defining infinity as largest int
	//each vertices distance is set to infinity
	vector<int> dist(n*m,INT_MAX);
	vector<bool> visited(n*m, false);
	
	dist[start] = 0;//distance of src(start) set to 0
	for (int i = 0; i <n*m; i++)
	{
        //find u 
		int min = INT_MAX,u;
		for (int k = 0; k < n*m; k++)
		{
			if (visited[k] == false && dist[k] <= min) {
				min = dist[k];
				u = k;
			}
		}
		visited[u]=true;
		for (int j = 0; j <n*m; j++)
		{
			if(!visited[j] && )
		}
	}
	
	//for (int i = 0; i <dist.size(); i++)
	//printing the result of src to dest(last node)alnog with src distance
	int result = first_val + dist.back();
		cout <<result  << endl;
	
}

int main() {

	int casenum;
	cin >> casenum;//number of case
	while (casenum--)
	{
		int n, m;
		cin >> n;//row
		cin >> m;//colum
	
			vector<vector<int>> maze(n, vector<int>(m));//matrix
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{//write val directly to matrix
					cin >> maze[i][j];
				}
			}
			cout << dijkstra(maze,0,maze[0][0],n,m) << endl;
		}//while-end
		return 0;
}//main-end