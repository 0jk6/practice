#include <iostream>
#include <queue>

using namespace std;

int main(){
	int arr[6] = {7,10,4,3,20,15};
	int k=3;

	priority_queue<int, vector<int>, greater<int>> minheap;

	for(int i=0; i<6; i++){
		minheap.push(arr[i]);
		if(minheap.size()>k)
			minheap.pop();
	}

	cout << "Kth Largest Element: " << minheap.top() << "\n";

	return 0;
}