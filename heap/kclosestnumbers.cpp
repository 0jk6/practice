#include <iostream>
#include <queue>

using namespace std;

int main(){
	int arr[5] = {5,6,7,8,9};
	int k=3;
	int x=7;

	//heap will be sorted according to the first value in the pair
	priority_queue<pair<int,int>> maxheap;

	for(int i=0; i<5; i++){
		maxheap.push({abs(x-arr[i]), arr[i]});
		if(maxheap.size()>k)
			maxheap.pop();
	}

	while(maxheap.size()>0){
		cout << maxheap.top().second << " ";
		maxheap.pop();
	}

	return 0;
}