//Min Stack using two stacks
#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

class MinStack{
public:

	stack<int> s; //to store elements
	stack<int> m; //to store minimum elements
	int me = INT_MAX;
	MinStack(){
		cout << "MinStack initialized\n";
	}

	void push(int data){
		if(data < me){
			me = data;
			m.push(me);
			s.push(data);
		}
		else{
			s.push(data);
		}
	}

	void pop(){
		if(s.top() == m.top()){
			s.pop();
			m.pop();
		}
		else{
			s.pop();
		}
	}

	int getMinElement(){
		return m.top();
	}
};

int main(){
	int arr[10] = {2,90,34,5,-2,-10,48,69,51,33};

	MinStack ms;

	for(int i=0; i<10; i++){
		ms.push(arr[i]);
	}

	cout << "Min Element: " << ms.getMinElement() << "\n";

	return 0;
}