#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	//maintain two stacks for NSL and NSR
	stack<pair<int, int>> s;
	stack<pair<int, int>> t;
	
	//maintain two vectors to store indexes of NSL and NSR
	vector<int> v;
	vector<int> b;

	int arr[7] = {6,2,5,4,5,1,6};
	
	//find NSR and push the indexes to the vector v
	int pseudo_index_nsr = 7; //assume smallest element towards right is at size(arr)

	for(int i=6; i>=0; i--){
		if(s.size()==0){
			v.push_back(pseudo_index_nsr);
		}
		else if(s.size()>0 && s.top().first < arr[i]){
			v.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first >= arr[i]){
			while(s.size()>0 && s.top().first >= arr[i]){
				s.pop();
			}
			if(s.size()==0){
				v.push_back(pseudo_index_nsr);
			}
			else{
				v.push_back(s.top().second);
			}
		}
		s.push({arr[i],i});
	}

	reverse(v.begin(), v.end());

	//find NSL and push the indexes to the vector b
	int pseudo_index_nsl = -1; //assume that the smallest element towards left is at -1

	for(int i=0; i<7; i++){
		if(t.size()==0){
			b.push_back(pseudo_index_nsl);
		}
		else if(t.size()>0 && t.top().first < arr[i]){
			b.push_back(t.top().second);
		}
		else if(t.size()>0 && t.top().first >= arr[i]){
			while(t.size()>0 && t.top().first >= arr[i]){
				t.pop();
			}
			if(t.size()==0){
				b.push_back(pseudo_index_nsl);
			}
			else{
				b.push_back(t.top().second);
			}
		}
		t.push({arr[i],i});
	}

	//find the ans by finding diff b/w the indexes of NSL and NSR
	vector<int> ans;
	for(int i=0; i<7; i++){
		ans.push_back((v[i]-b[i]-1)*arr[i]);
	}
	
	

	cout << *max_element(ans.begin(), ans.end()) << "\n";

	return 0;
}