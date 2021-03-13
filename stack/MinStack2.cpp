#include <iostream>
#include <stack>

using namespace std;

class MinStack{
public:
	MinStack(){
		cout << "MinStack Initialized.\n";
	}

	stack<int> s;
	int minEle;

	void push(int data){
		if(s.size() == 0){
			minEle = data;
			s.push(data);
			return;
		}
		if(data >= minEle){
			s.push(data);
		}
		else{
			s.push(2*data - minEle);
			minEle = data;
		}
	}

	void pop(){
		if(s.top() > minEle){
			s.pop();
		}
		else{
			minEle = 2*minEle - s.top();
			s.pop();
		}
	}

	int peek(){
		if(s.top()>minEle){
			return s.top();
		}
		else{
			return minEle;
		}
	}

	int getMinElement(){
		if(s.size()==0)
			return -1;
		return minEle;
	}

};


int main(){
	int arr[10] = {2,90,34,5,-2,-10,48,69,51,33};

	MinStack ms;

	for(int i=0; i<10; i++){
		ms.push(arr[i]);
	}

	cout << "Min Element: " << ms.getMinElement() << "\n";

	for(int i=0; i<5; i++)
		ms.pop();

	cout << "Min Element: " << ms.getMinElement() << "\n";

	return 0;
}