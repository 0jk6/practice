#include <iostream>
#include <string.h>

using namespace std;

bool equalpartition(int arr[], int n){
	//first find the sum of all the elements
	int s = 0;
	for(int i=0; i<n; i++)
		s+=arr[i];
	//if sum is odd, then return false, because we cannot partition it into equal sum sub array
	if(s&1)
		return false;
	s = s/2;
	//now find the subset with the sum equals to s/2
	bool dp[n+1][s+1];
	memset(dp, 0, sizeof(dp));
	//fill up the first row and columns
	for(int i=0; i<n+1; i++)
		dp[i][0]=false;
	for(int i=0; i<s+1; i++)
		dp[0][i]=true;

	//now process the given inputs
	for(int i=1; i<n+1; i++){
		for(int j=1; j<s+1; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][s];
}

int main(){
	int arr[4] = {1,5,11,5};
	int n = 4;

	cout << equalpartition(arr, n) << "\n";

	return 0;
}