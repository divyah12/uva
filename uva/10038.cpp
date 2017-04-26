#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	int n,a[3000],d[3000],t;
	while (cin >> n) {
		t = 1;
		for (size_t i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (size_t i = 0; i < n - 1; i++)
		{
			d[i] = abs(a[i + 1] - a[i]);
		}
		sort(d, d + n - 1);
		for (size_t i = 0; i < n - 1; i++)
		{
			if (d[i] != i + 1) {
				t = 0;
				break;
			}
		}
		if (t == 0) {
			cout << "Not jolly" << endl;
		}
		else {
			cout << "Jolly" << endl;
		}
	}
	return 0;
}