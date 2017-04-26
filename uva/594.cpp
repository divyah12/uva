//**************************************************************
//                   Project 12 Little Endians 
//                    Name: Divyashree hb
//                    Data Structures Date: 10/02/2016
//***************************************************************
#include<iostream>
#include<string>
#include<bitset>
#define endl '\n'

using namespace std;

int main() {
	long N;
	int temp;
	while (cin >> N) {
		
		bitset<32> a(N),res;
		temp = 24;
		for (int i = 0; i < 8; i++)
		{
			if (a[i]) {
				res |= (1 << temp);
			}
			temp++;
		}
		temp = 16;
		for (int i = 8; i < 16; i++)
		{
			if (a[i]) {
				res |= (1 << temp);
			}
			temp++;
		}
		temp = 8;
		for (int i = 16; i < 24; i++)
		{
			if (a[i]) {
				res |= (1 << temp);
			}
			temp++;
		}
		temp = 0;
		for (int i = 24; i <32; i++)
		{
			if (a[i]) {
				res |= (1 << temp);
			}
			temp++;
		}
		int result = res.to_ulong();
		cout<<N << " converts to " << result<< endl;
	}
	
	return 0;
}
//I have written the entire program as turned in and have not copied this code, or parts of this code from the internet or another student.

//Signature____________________

