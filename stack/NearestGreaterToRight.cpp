//Next Greater Element or Nearest Greater Element to Right

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	 int arr[4] = {1,3,2,4};

	 vector<int> v;
	 stack<int> s;

	 for(int i=3; i>=0; i--){
	 	if(s.size()==0){
	 		v.push_back(-1);
	 	}
	 	else if(s.size() > 0 && s.top() > arr[i]){
	 		v.push_back(s.top());
	 	}
	 	else if(s.size() > 0 && s.top() <= arr[i]){
	 		while(s.size()>0 && s.top() <= arr[i]){
	 			s.pop();
	 		}
	 		if(s.size()==0){
	 			v.push_back(-1);
	 		}
	 		else{
	 			v.push_back(s.top());
	 		}
	 	}
	 	s.push(arr[i]);
	 }

	 for(auto it = v.end()-1; it!=v.begin()-1; it--){
	 	cout << *it << " ";
	 }

	return 0;
}