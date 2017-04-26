#include <iostream>
#include<string>
using namespace std;
int main()
{
	std::string str1 = " WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./1234567890-=";
	std::string str2 = " QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.`1234567890-";
	char table[127];
	for (size_t i = 0; i < str1.length(); i++)
	{
		table[str1[i]] = str2[i];
	}
	std::string cmpstr;
	while (getline(cin, cmpstr)) {
		for (size_t i = 0; i < cmpstr.length(); i++)
		{
			cout << table[cmpstr[i]];
		}
		

		cout << endl;
	}return 0;
}