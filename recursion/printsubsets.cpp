#include<bits/stdc++.h>

using namespace std;

int printSubsets(int arr[], int i, int n, string osf){
	//base case
	if(i==n){
		cout << "[" << osf << "]\n";
		return 0;
	}
	return printSubsets(arr, i+1, n, osf + to_string(arr[i]) + ",") || printSubsets(arr, i+1, n, osf);
}

int main(){
	int arr[3] = {3,2,1};

	printSubsets(arr, 0, 3, "");

	return 0;
}