//10895 matrix transpose
#include <iostream>
#include<sstream>
#include<vector> 
#include<string>
#define endl '\n'
using namespace std;

int main() {
	// your code goes here
	//vector of vector pair(index,val)
	string str;

	int m, n, r, intemp;
	while (cin >> m >> n) {
		//cout << m << '\t' << n <<  endl;
		vector<vector<pair<int, int> > > alist(m + 1);
		vector<vector<pair<int, int> > > translist(n + 1);
		for (int i = 1; i <= m; i++) {
			cin >> r;
			if (r != 0) {//empty if 0
				for (int j = 1; j <= r; j++) {
					cin >> intemp;//position
					alist[i].push_back(make_pair(intemp, 0));
				}
				for (int j = 0; j < r; j++) {
					cin >> intemp;//update value
					alist[i][j].second = intemp;
				}
			}
		}
		//transpose
		for (int i = 1; i <= m; i++) {
			if (!alist[i].empty()) {
				for (int j = 0; j < alist[i].size(); j++) {
					translist[alist[i][j].first].push_back(make_pair(i, alist[i][j].second));
				}
			}
		}
		//print matrix
		cout << n << " " << m << endl;
		for (int i = 1; i <= n; i++) {
			if (!translist[i].empty()) {
				intemp = translist[i].size();
				cout << intemp;
				for (int j = 0; j < intemp; j++) {
					cout << " " << translist[i][j].first;
				}
				cout << endl;
				cout << translist[i][0].second;
				for (int j = 1; j < intemp; j++) {
					cout << " " << translist[i][j].second;
				}
				cout << endl;
			}
			else
			{
				cout << "0" << endl;
				cout << endl;
			}
		}
	}
	return 0;
}