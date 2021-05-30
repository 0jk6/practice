#include <iostream>
#include <cmath>

using namespace std;

void printSubsets(string &s){
	int len = s.length();

	int n = pow(2, len); //8 if len = 3

	//if n = 3, then we will have 2^3 subsets
	//we will have the following binary numbers for n = 3
	/*
		0 0 0
		0 0 1
		0 1 0
		0 1 1
		1 0 0
		1 0 1
		1 1 0
		1 1 1

		if the string is "abc", then we will print
		individual characters according to the above binary sequence above

		eg: for 101 we will print ac, for 001, we will print c
	*/

	for(int i=0; i<n; i++){
		
		string res = "";
		int num = i;

		for(int j=0; j<len; j++){
			if(num & 1)
				res.push_back(s[j]);

			num = num >> 1; //perform right shift
		}
		cout << res << "\n";
	}
}


int main(){
	string s;
	cin >> s;

	printSubsets(s);

	return 0;
}