//Top K frequent elements
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){
	int arr[7] = {1,1,1,3,2,2,4};
	int k=2;

	unordered_map<int,int> mp;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

	//store the frequencies of elements in the array using unordered map
	for(int i=0; i<7; i++){
		mp[arr[i]]++;
	}

	//now store them in the heap
	//the first element in the pair of heap should be the frequency
	//so that the elements in the heap are sorted according to the frequency
	for(auto it: mp){
		minheap.push({it.second, it.first});
		if(minheap.size()>k){
			minheap.pop();
		}
	}

	//now the heap contains required elements
	//the second part in the pair gives the element
	//and the first part of the pair gives frequency
	while(minheap.size()>0){
		cout << minheap.top().second << " ";
		minheap.pop();
	}

	return 0;
}