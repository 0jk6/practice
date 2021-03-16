#include <iostream>
#include <queue>

using namespace std;
int main(){
	int arr[6] = {1,3,12,5,15,11};
	int k1 = 3;
	int k2 = 6;

	int f = 0;
	int s = 0;
	int sum = 0;
	priority_queue<int> maxheap;
	
	for(int i=0; i<6; i++){
		maxheap.push(arr[i]);
		if(maxheap.size()>k1)
			maxheap.pop();
	}

	f = maxheap.top();
	maxheap.pop();

	//empty the maxheap
	while(maxheap.size()>0)
		maxheap.pop();

	for(int i=0; i<6; i++){
		maxheap.push(arr[i]);
		if(maxheap.size()>k2)
			maxheap.pop();
	}

	s = maxheap.top();
	maxheap.pop();

	for(int i=0; i<6; i++){
		if(arr[i]>f && arr[i]<s)
			sum+=arr[i];
	}

	cout << sum << "\n";

	return 0;
}