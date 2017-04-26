//**************************************************************
//                   Project 11 Lonesome Cargo
//                    Name: Divyashree hb
//                    Data Structures Date: 09/27/2016
//***************************************************************
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define endl '\n'

using namespace std;

int main() {

	int in_set, N, S, Q;//numberofinput,stacksize,queuesize
	cin >> in_set;//numofcase
	int cargonum = 0;
	for (int i = 0; i < in_set; i++)
	{
		cin >> N >> S >> Q;
		//std::cout << N << S << Q << endl;
		vector<queue<int>>V(N);
		stack<int> C;
		for (int i = 0; i < N; i++)//get input setlines i.e. station details
		{
			int temp, inval;
			cin >> temp;
			cargonum += temp;
			for (int j = 0; j < temp; j++)
			{
				cin >> inval;
				V[i].push(inval - 1);//vector with station queue
			}
		}
		int restime = 0, k = 0;//k holds the subscript value
		//std::cout << "cargo  " << cargonum << endl;

		while (cargonum)
		{

			//unload cargo 
			while (!C.empty())
			{
				if (C.top() == k) 
				{
					cargonum--;
				}//queue full
				else if( V[k].size()<Q)
				{
				  V[k].push(C.top());
				}
				else
				{
					break;
				}
				//unload @ station A
				C.pop();
				restime++;
		}

			//load cargo 
			while ((C.size() < S) && !V[k].empty()) {
				C.push(V[k].front());
				V[k].pop();
				restime++;
			}

			//cout << "k" << k << endl;
			//k++;
			//if (k == N) k = 0;
			k = (k + 1) % N;
			//cout << "restime" << restime << endl;
			restime += 2;
		
	}


		/*//print content
		for(int t=0;t<V.size();t++) {
		while(!V[t].empty())
		{
		std::cout << V[t].front() <<" ";
		V[t].pop();
		}
		std::cout << endl;
		}*/
		std::cout <<  restime - 2 << endl;
	}

	return 0;
}
//I have written the entire program as turned in and have not copied this code, or parts of this code from the internet or another student.

//Signature____________________

		