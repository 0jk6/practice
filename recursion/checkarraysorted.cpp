#include<bits/stdc++.h>

using namespace std;

bool check(int arr[], int n){
	if(n==0)
		return true;

	if(arr[n] < arr[n-1])
		return false;

	return check(arr, n-1);
}

int main(){
	int arr[8] = {1,2,3,4,5,6,7,8};

	cout << check(arr, 8) << "\n";

	return 0;
}