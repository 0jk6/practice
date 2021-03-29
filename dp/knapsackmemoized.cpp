//knapsack with memoization
#include <iostream>
#include <string.h>

using namespace std;


// global dp matrix
int dp[100][100];

int knapsack(int wt[], int val[], int W, int n){
	//Base case

	if(n==0 || W==0){
		return 0;
	}
	//if the values is in dp table, return the value from dp table
	if(dp[n][W] != -1){
		return dp[n][W];
	}
	//else process and store it in dp table
	else{
		if(wt[n-1]<=W){
			return dp[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
		}
		else{
			return dp[n][W] = knapsack(wt, val, W, n-1);
		}
	}
}

int main(){
	memset(dp, -1, sizeof(dp)); //initialize with -1s in dp

	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;
	int n = 3;
	cout << knapsack(wt, val, W, n) << "\n";

	return 0;
}