#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	
	int caseval;
	cin >> caseval;
	for (size_t i = 0; i < caseval; i++)
	{
		int n,j;
		cin >> n;
		j = n;
		vector<int> p, q;
			for (size_t i = 0; i < n; i++)
			{
				int ain;
				cin >> ain;
				p.push_back(ain);
			}
			for (size_t i = 0; i < n; i++)
			{
				int ain;
				cin >> ain;
				q.push_back(ain);
			}
		
			for(j=1;j<=n;j++) {
				for (size_t i = 0; i < n; i++)
				{
					if (p[i] - q[i] != 0 && p[i]-q[i]<0) {
						
					}

				}
			}

		

	}
	
	return 0;
}