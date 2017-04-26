#include <iostream>
#include<map>
#include<string>
#include<iomanip>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	//empty line
	getline(cin, str);
	getline(cin, str);//new line
	for (int i = 0; i < n; i++)
	{
		map<string, double>t;
		int count = 0;
			while (getline(cin, str) && str!="")
			{
				t[str]++;//tree in vector
				count++;//total list number
			}
			for (auto it = t.cbegin(); it != t.cend(); it++)
			{
				//%of each tree
				double temp = it->second;
				temp /= count;
				temp *= 100;
				cout << it->first << " " << fixed << setprecision(4) << temp << endl;
			}
			//t.clear();
			if(i!=n-1)
			cout << endl;
	}
	return 0;
}