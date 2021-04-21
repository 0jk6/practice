#include <iostream>

using namespace std;

int squareRoot(int n){
	if(n==0 || n==1)
		return n;
	int low = 1, high = n-1;
	int ans = -1;

	while(low <= high){
		int mid = low + (high-low)/2;
		
		if(mid*mid == n){
			return mid; //perfect square
		}
		else if(mid*mid > n){
			//everything from here and after will be greater than n
			//so, we move high to mid-1
			high = mid-1;
		}
		else{
			//if mid*mid is < n, we don't need left half
			//we move to the right half of the array
			ans = mid;
			low = mid+1;
		}
	}

	return ans;
}


int main(){

	int n;
	cin >> n;
	cout << "Square Root: " << squareRoot(n) << "\n";

	return 0;
}