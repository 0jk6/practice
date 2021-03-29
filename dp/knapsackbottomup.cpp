//knapsack bottom up solution
#include <iostream>
#include <string.h>

using namespace std;

int knapsack(int wt[], int val[], int W, int n){
	//initialize dp array
	int dp[n+1][W+1];
	//fill the dp array with 0s whenever n = 0 or W = 0
	for(int i=0; i<n+1; i++){
		for(int j=0; j<W+1; j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}

	//now process the values and store it in dp table
	//we have already initialized column 0 and row 0, so
	//traverse from column 1 and row 1
	for(int i=1; i<n+1; i++){
		for(int j=1; j<W+1; j++){
			//we have two choices now
			//decide whether to include it or not
			if(wt[i-1] <= W){
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
			else{
				//if weight of item is greater than the capacity of knapsack
				//we don't include it and fill the table with the previous solution
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	//return the last element in the dp table to get the answer
	return dp[n][W];
}

int main()
{
	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;
	int n = 3;
	cout << knapsack(wt, val, W, n) << "\n";
	return 0;
}