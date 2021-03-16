#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){
	int arr[7] = {1,1,1,3,2,2,4};

	unordered_map<int, int> mp;
	priority_queue<pair<int, int>> maxheap;

	for(int i=0; i<7; i++){
		mp[arr[i]]++;
	}

	for(auto it: mp){
		maxheap.push({it.second, it.first});
	}

	while(maxheap.size()>0){
		int freq = maxheap.top().first;
		for(int i=0; i<freq; i++){
			cout << maxheap.top().second << " ";
		}
		maxheap.pop();
	}

	return 0;
}