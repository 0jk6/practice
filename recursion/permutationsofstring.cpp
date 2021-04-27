#include <bits/stdc++.h>
using namespace std;

void permuteRecursive(string str, string osf){
	if(str.size()==0){
		cout << osf << "\n";
		return;
	}
	for(int i=0; i<str.size(); i++){
		char ch = str[i];
		permuteRecursive(str.substr(0, i)+str.substr(i+1), osf+ch);
	}
}

//Backtracking
void permute(string a, int l, int r){
	// Base case
	if (l == r)
		cout<<a<<endl;
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l+1, r);

			//backtrack
			swap(a[l], a[i]);
		}
	}
}


int main(){
	string str = "ABC";
	int n = str.size();
	//permute(str, 0, n-1);
	permuteRecursive(str, "");
	return 0;
}
