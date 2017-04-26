#include<iostream>
#include<string>
#include<sstream>

using namespace std;
int checkalnum(string str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i])) {
			if (i + 1 != str.length()) {
				return i;
				break;
			}
		}
	}
	return 0;
}
int main() {
	
	string str;
	while (getline(cin, str))
	{
		int t,icount=0,count=0,temp=0;
		stringstream ss(str);
		while (ss) {
			string cstr;
			ss >> cstr;
			//cout << cstr << endl;
			if (isalpha(cstr[0])) {
				count++;
				t = checkalnum(cstr);
				for (size_t i = t; i < cstr.length(); i++)
				{
					if (!isalpha(cstr[i]) && isalpha(cstr[i + 1])) {
						//cout << i << '\t' << count << endl;
						count++;
						//cout << count << endl;
					}
				}

			}
			else
			{
				for (size_t i = 0; i < cstr.length(); i++)
				{
					if (!isalpha(cstr[i]) && isalpha(cstr[i + 1])) {
						//cout << i << '\t' << count << endl;
						count++;
						//cout << count << endl;
					}
				}

			}
		}
	    
		cout << count << endl;
		//cout << count<<'\t'<<icount<<endl;
	}
	return 0;
}