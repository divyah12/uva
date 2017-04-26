// 118.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include<string>
#include<vector>
#define endl '\n'

using namespace std;

char direction(char c,char op) {
	if (c == 'N') {
		if (op == 'L')
			c = 'W';
		else
			c = 'E';
	}
	else if (c == 'S') {
		if (op == 'L')
			c = 'E';
		else
			c = 'W';
	}
	else if (c == 'E') {
		if (op == 'L')
			c = 'N';
		else
			c = 'S';
	}
	else {
		if (op == 'L')
			c = 'S';
		else
			c = 'N';
	}

	return c;
}

int main()
{
	int x, y, m, n;
	char c;
	
	cin >> x;
	cin >> y;
	vector<pair<int, char>> tracklost;
	while (cin >> m) {//x coordinate
		string str;
		bool lost = false;
		cin >> n >> c;//y coordinate //N,S,E,W
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'F') {
				
					if (c == 'N') { 
						if (n < y)
							n++;
						else
							lost = true;
					}
					else if (c == 'S') {
						if (n > 0)
							n--;
						else
							lost = true;
					 }
					else if (c == 'E') {
						if (m < x)
							m++;
						else
							lost = true;
					 }
					else {
						if (m > 0)
							m--;
						else
							lost = true;
					}
			}
			else {
				c = direction(c, str[i]);
			}
			if (lost) {
				bool found = false;
					for (int i = 0; i < tracklost.size(); i++) {
						if (tracklost[i].first == m && tracklost[i].second == n) {
							lost = false;
							found = true;
							break;
						}						
 					}
					if (!found) {
						tracklost.push_back(make_pair(m, n));
						break;
				}
			}
		}
		cout << m << " " << n << " " << c;
		if (lost)
			cout << " LOST";
		cout<< endl;
	}
    return 0;
}

