// 100.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include <algorithm>

using namespace std;

int maxcyclelength(int t) {
	
	int count = 1;
	while (t != 1) {
		if (t % 2 == 0) {
			t = t / 2;
		}
		else
		{
			t = 3 * t + 1;
		}
		count++;
	}
	
	return count;
}

int main()
{
	int a,b;
	while (cin >> a >> b) {
		int maxcycle = 0;
		int m = min(a,b);
		int n = max(a,b);
		if (a==b) {
			maxcycle = maxcyclelength(a);
		}
		else
		{
			int temp = 0;
			for (int i = m; i <=n; i++)
			{
				int count ;
				count=maxcyclelength(i);
				if (count>maxcycle)   maxcycle =count;
			}
		}
		
		cout << a << ' ' << b << ' ' << maxcycle << endl;
	}
    return 0;
}


