//Count of subset sums with a given sum
#include <iostream>

using namespace std;

int countOfSubsetSum(int arr[], int sum, int n){
	//initialize dp table
	//as we are counting the number of subsets that are equal to given sum
	//we will use an integer datatype
	int dp[n+1][sum+1];

	//fill up the dp table's first row and column
	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if(i==0)
				dp[i][j]=0;
			if(j==0)
				dp[i][j]=1;
		}
	}

	//now process the given array to find the subset sums
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1] <= j){
				//decide whether to exclude it or not
				dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
			}
			else{
				//exclude the current element
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
		cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return dp[n][sum];
}


int main(){
	int arr[6] = {2,3,5,6,8,10};
	int sum = 10;
	int n = 6;

	cout << countOfSubsetSum(arr, sum, n) << "\n";
	return 0;
}