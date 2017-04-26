#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main() {
	
	long long n, num = 1;
	while (cin >> n) {
		int res = 1;
		if (n == 1) {
			cout << n << endl;
		}
		else
		{
			while (num%n!=0)
			{
				num =(num%n)* 10;
				num += 1;
				res++;
			}
			cout << res << endl;
			num = 1;
		}
	}
	
	return 0;
}