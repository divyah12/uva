#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>//setpression
#define endl '\n'

using namespace std;

int main() {
	int N, a;//a is the length of the square
	while (cin>>N>>a)
	{//read N and a break for EOF condition i.e,0 0
		if (N == 0 && a == 0) {
			break;
		}
		int m=0;
		for (int i = 0; i <N; i++)
		{//reading the co-ordinates
			double x, y;
			cin >> x;
			cin >> y;
			//if distance btw the given point(M) and the corners of the sqaure is <= to given lenghth of the side(a)
			if (sqrt((x*x)+(y*y)) <= a) {//dist A(0,0) and M(x,y)
				if (sqrt(((x-a)*(x-a))+(y*y)) <= a) {//dist B(a,0) and M(x,y)
					if (sqrt(((x - a)*(x - a)) + ((y - a)*(y - a))) <= a) {//dist C(a,a) and M(x,y)
						if (sqrt((x*x) + ((y - a)*(y - a))) <= a) {//dist D(0,a) and M(x,y)
							m++;
						}
					}
				}
			}
		}
		//result formatting
		cout.precision(5);
		cout << fixed;
		cout<< (double)m*a*a / N << endl;
	}
	return 0;
}