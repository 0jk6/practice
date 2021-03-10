//Stock Span problem

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	
	int arr[7] = {100,80,60,70,60,75,85};
	vector<int> v;
	//first element in stack is NGL and second is its index
	stack<pair<int, int>> s;


	for(int i=0; i<7; i++){
		if(s.size()==0){
			v.push_back(-1);
		}
		//while comparing we need to compare the arr[i] with 
		//the first element in the pair stored in stack, because it is NGL
		else if(s.size()>0 && s.top().first>arr[i]){
			//we have a pair in stack and we need the index
			v.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first<=arr[i]){
			while(s.size()>0 && s.top().first<=arr[i]){
				s.pop();
			}
			if(s.size()==0){
				v.push_back(-1);
			}
			else{
				v.push_back(s.top().second);
			}
		}
		//push the pair of arr[i] and i into the stack
		s.push({arr[i], i});
	}
	
	//Now we have vector v with indexes of NGLs
	//now we need to subtract it from 0 to n and we get the answer
	int tmp = 0;

	for(auto it = v.begin(); it!=v.end(); it++){
		cout << tmp - *it << " ";
		tmp++;
	}

	return 0;
}