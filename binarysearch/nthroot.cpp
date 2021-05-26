//Nth root of a number upto d decimal places using binary search
//Time Complexity = O(n*log(M*10^d))

#include <iostream>

using namespace std;

double multiply(double mid, double n){
	double ans = 1.0;
	for(int i=0; i<n; i++){
		ans = ans*mid;
	}
	return ans;
}

double solve(int n, int m){
	//calculate nth root of m upto d decimal places
	double low = 1;
	double high = m;

	double eps = 1e-6; //for 5 decimal places
	double mid = 0;

	//we will perform binary search until all the decimal places of high and low are equal
	while((high - low) > eps){
		mid = low + (high - low)/2.0;

		if(multiply(mid, n) < m){
			low = mid;
		}
		else{
			high = mid;
		}
	}

	return mid;
}


int main(){
	int n, m;
	cin >> n >> m;

	cout << solve(n, m) << "\n";

	return 0;
}