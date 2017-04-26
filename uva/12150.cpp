#include <iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main() {
	int n, a, b,*res;
	while (cin >> n && n > 1)
	{
		res = new int[n]();
		int t = 1;
		bool temp = true;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (i + b >= 0 && i + b < n) {
				if (res[i + b] == 0) {
					res[i + b] = a;
				}
				else
				{
					t = 0;
				}
			}
			else
			{
				t = 0;
			}
		}
		if (t == 1) {

			for (size_t i = 0; i < n; i++)
				cout << res[i] <<' ';
			cout << endl;
		}
		else
		{
			cout <<"-1"<<endl;
		}
		
	}
	return 0;
}