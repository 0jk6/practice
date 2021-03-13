#include <iostream>

using namespace std;

int main(){
	int arr[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int size = 12;

	int maxL[size], maxR[size], water[size];

	//initialize first element of maxL array with arr's initial value
	maxL[0]=arr[0];
	//store the maximum element in the left array from the current element
	for(int i=1; i<size; i++){
		maxL[i] = max(maxL[i-1], arr[i]);
	}

	//initialize last element of maxR with the last element of arr
	maxR[size-1]=arr[size-1];
	//store the maximum element in the right array from the current element
	for(int i=size-2; i>=0; i--){
		maxR[i] = max(maxR[i+1], arr[i]);
	}

	//get the minimum element from the maxL and maxR arrays
	//and subtract the building height and store it in water[] array
	for(int i=0; i<size; i++){
		water[i] = min(maxL[i], maxR[i]) - arr[i];
	}

	int sum=0;

	for(int i=0; i<size; i++){
		sum += water[i];
	}

	cout << sum << "\n";

	return 0;
}