#include <iostream>
#include <queue>

using namespace std;

int main(){
	int arr[6] = {7,10,4,3,20,15};
	int k=3;
	priority_queue<int> maxheap;

	for(int i=0; i<6; i++){
		maxheap.push(arr[i]);
		if(maxheap.size()>k){
			maxheap.pop();
		}
	}

	cout << "Kth Smallest Element: " << maxheap.top() << "\n";

	return 0;
}