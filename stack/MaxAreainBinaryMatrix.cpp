//Maximum area of rectangle in a binary matrix
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

//maximum area of histogram function
int mah(int arr[], int n){
	stack<pair<int, int>> s;
	stack<pair<int, int>> t;
	
	//maintain two vectors to store indexes of NSL and NSR
	vector<int> v;
	vector<int> b;
	
	//find NSR and push the indexes to the vector v
	int pseudo_index_nsr = n; //assume smallest element towards right is at size(arr)

	for(int i=n-1; i>=0; i--){
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

	for(int i=0; i<n; i++){
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
	for(int i=0; i<n; i++){
		ans.push_back((v[i]-b[i]-1)*arr[i]);
	}

	return *max_element(ans.begin(), ans.end());
}

int main(){
	int arr[4][4] = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};

	//store the heights of individual arrays from the given matrix
	int ans[4];
	for(int i=0; i<4; i++){
		ans[i]=(arr[0][i]);
	}

	//find the max area for individual arrays
	int mx = mah(ans,4);

	for(int i=1; i<4; i++){
		for(int j=0; j<4; j++){
			if(arr[i][j]==0)
				ans[j]=0;
			else
				ans[j] = ans[j] + arr[i][j];
		}
		mx = max(mx, mah(ans,4));
	}

	cout << mx << "\n";

	return 0;
}