#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str)) {
		string  str1, str2;
		stringstream ss(str);
		ss >> str1 >> str2;
		int n = 0;
		if (stoi(str1) != 0) {
			n = (str2.length() / stoi(str1));
			//cout << n << str2 << endl;
			for (size_t i = 0; i < str2.length(); i = i + n)
			{
				str1 = str2.substr(i, n);
				//cout << str1 << endl;
				for (string::reverse_iterator i = str1.rbegin(); i != str1.rend(); i++)
				{
					cout << *i;
				}
				//cout << endl;
			}cout << endl;
		}
	}
	return 0;
}