//connect ropes to minimize the cost
#include <iostream>
#include <queue>

using namespace std;

int main(){
	int arr[5] = {1,2,3,4,5};
	int cost = 0;

	//use min heap to get the minimum elements and add them
	priority_queue<int, vector<int>, greater<int>> minheap;

	//first push all the elements into the min heap
	for(int i=0; i<5; i++){
		minheap.push(arr[i]);
	}

	//now get two minimum elements and add them and push them back into the minheap
	//also update the cost
	while(minheap.size()>1){
		int a = minheap.top();
		minheap.pop();
		int b = minheap.top();
		minheap.pop();
		cost += a+b;
		minheap.push(a+b);
	}

	cout << "Minimized cost: " << cost << "\n";

	return 0;
}