#include<iostream>
#include<vector>

using namespace std;
#define max 1000001
#define endl '\n'
//int p[1000000];
int main()
{
	//sieve
	vector<bool> p(max, true);
	vector<int> primeset;
	p[0] = p[1] = 0;
	int e, o;
	for (int i = 4; i <max; i += 2)
	{//all even numbers
		p[i] = false;
	}
	for (int i = 3; i < max; i += 2)
	{//for prime no.
		if (p[i]) {
			primeset.push_back(i);
			for (int j = i + i; j <max; j += i)
			{
				p[j] = false;
			}
		}
	}
	//cout << "entering to solve problem" << endl;
	//problem
	int n, a, b;
	bool temp = false;
	while (cin >> n && n)
	{
		for (int i = 0; i <primeset.size(); i++)
		{
			a = primeset[i];
			//cout << a << endl;
			for (int j = 0; j < primeset.size(); j++) {
				b = primeset[j];
				//cout << b << endl;
				if (a + b > n || a + b == n)
					break;

			}
			if (a + b == n) {
				break;
			}

		}
		if (a + b == n)
			cout << n << " = " << a << " + " << b << endl;
		else
			cout << "Goldbach's conjecture is wrong" << endl;


	}
	return 0;
}

