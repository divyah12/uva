#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

long long intRev(long long x) {
	long long n = x, num = 0;
	while (n > 0)
	{
		num = (num * 10) + (n % 10);
		n /= 10;
	}
	return num;
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long addcount = 0, x, xin, revx;
		cin >> xin;
		do {
			revx = intRev(xin);
			
			xin = xin + revx;
			addcount++;
			revx = intRev(xin);
		} while (xin!=revx);
					cout << addcount << ' ' << xin << endl;
		
	}
	return 0;
}