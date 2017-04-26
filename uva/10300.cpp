#include<iostream>
#include<stdint.h>

using namespace std;

int main() {
	
	int n;
	long long res;
	cin >> n;
	for (size_t i = 0; i <n; i++)
	{
		long long fam,env,fsize,ani;
		 res = 0;
		cin >> fam;
		for (size_t i = 0; i < fam; i++)
		{
			cin >> fsize >> ani >> env;
			//cout << fsize << '\t' << ani << '\t' << env << endl;
			res+=( fsize*env);
		}
		cout << res << endl;
	}
	
	
	return 0;
}
