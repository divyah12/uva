#include<iostream>
#include<string>
#include<vector>

using namespace std;

int m, n;
char field[100][100];
//green book tip
int dr[] = { 0,0,1,1,-1,-1,1,-1 }; // trick to explore an implicit 2D grid
int dc[] = { 1,-1,1,-1,1,-1,0,0 }; // S,SE,E,NE,N,NW,W,SW neighbors

void dfs_floodfill(int x, int y) {
	
	
		if (x >= 0 && x<m && y >= 0 && y<n) {
			if (field[x][y] == '@') {
				//x += dr[i];
				//y += dc[i];
				field[x][y] = '*';
				for (int i = 0; i < 8; i++)
				{
					dfs_floodfill(x + dc[i], y + dr[i]);

				}
			}
			else
				return;
		}
		else
			return;
}

int main() {

	int count;
	char c;
	string str;
	while (cin>>m >> n) {
		if (m == 0)break;
		//cout << m << " " << n << endl;
		//read matrix
		for (int i = 0; i < m; i++) {
			//getline(cin, str);
			//cout << str << endl;
			for (int j = 0; j <n; j++)
			{
				cin >> c;
				field[i][j] = c;//@ and * 
				//cout << field[i][j] << " ";
			}
			//cout << endl;
		}	
		count = 0;
		//count oil in the field matrix
		for (int i = 0; i<m; i++) {
			//travese the matrix for @ 
			for (int j = 0; j <n; j++){
					if (field[i][j] != '*') {
					   dfs_floodfill(i,j);
						count++;
					}
				}
			}//<<"count--->"
		cout << count << endl;
	}
	return 0;
}