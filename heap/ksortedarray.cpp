//Sort a K sorted array or Nearly Sorted array
#include <iostream>
#include <queue>

using namespace std;

int main(){
	int arr[7] = {6,5,3,2,8,10,9};
	int k=3;

	//use minheap
	priority_queue<int, vector<int>, greater<int>> minheap;

	for(int i=0; i<7; i++){
		minheap.push(arr[i]);
		if(minheap.size()>k){
			cout << minheap.top() << " ";
			minheap.pop();
		}
	}

	while(minheap.size()>0){
		cout << minheap.top() << " ";
		minheap.pop();
	}

	return 0;

}