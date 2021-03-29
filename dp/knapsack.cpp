#include <iostream>

using namespace std;

//wt[] -> weight array
//val[] -> value array
//W -> capacity
int knapsack(int W, int wt[], int val[], int n){
	if(n==0 || W == 0)
		return 0;

	//if weight of nth item is more than Knapsack capacity W
	//then we won't include it in the knapsack
	if(wt[n-1] > W){
		//return with the same values
		return knapsack(W, wt, val, n-1);
	}
	else{
		//we have two cases here
		//if nth item is included, we get one value
		//if nth item is not included, we get another value
		//To maximize the profit, we return max of these two items

		//when this item is included we add val[n-1] and subtract wt[n-1] from W
		return max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
	}
}

int main(){
	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;
	int n = 3;
	cout << knapsack(W, wt, val, n) << "\n";
	return 0;
}