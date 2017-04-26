#include <iostream>
#include<string>
using namespace std;
int main()
{
	int n,a[10],max;
	string url[10];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Case #" << i << ":" << endl;
		max = 0;
		for (size_t j = 0; j < 10; j++)
		{
			cin >> url[j] >> a[j];
			if (a[j] > max)
				max =a[j];
		}
		
		for (size_t k = 0; k < 10; k++)
		{
			if(a[k]==max)
			cout << url[k]<<endl;
		}
	}
	return 0;
}