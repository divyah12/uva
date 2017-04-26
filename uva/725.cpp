#include <iostream>
#include<fstream>
#include <algorithm>
#include <string>
#include<vector>
#define endl '\n'
using namespace std;

int main()
{
	vector<vector<pair<string,string>>> number(80);
//ofstream myfile("example.txt");
	std::string s = "1234567890";
	std::sort(s.begin(), s.end());
	do {
		int num, den;
		num = stoi(s.substr(0, 5));
		den = stoi(s.substr(5, 9));
		int i = num / den;
		if ((i*den)==num) {
			number[i].push_back(make_pair(s.substr(0, 5), s.substr(5,9)));
			//myfile << i << '\t' << s.substr(5, 9) << '\t' << s.substr(0, 5) << '\n';
		}		
//myfile.open("example.txt");
	} while (std::next_permutation(s.begin(), s.end()));
//myfile.close();
	
	int num;
	bool temp = true;
	while (cin >> num && num != 0) {
		if (!temp) { cout << endl; }
		temp = false;
		//cout << num << endl;
		if (num>79 || number[num].size()==0) {
			cout << "There are no solutions for " << num << "." << endl;
		}
		else
		{
			vector<pair<string, string> > ::iterator i;
			for (i = number[num].begin(); i != number[num].end(); i++) {
				cout << i->first << " / " << i->second <<" = "<<num<< endl;
			}
		}	
	}
	return 0;
}