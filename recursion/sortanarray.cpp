#include <iostream>

using namespace std;

//recursive bubble sort
int sort(int arr[], int n){
	if(n==1)
		return 0;

	for(int i=0; i<n-1; i++){
		if(arr[i] > arr[i+1]){
			int tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
		}
	}

	return sort(arr, n-1);
}

int main(){
	int arr[10] = {4,5,1,3,2,6,10,7,9,8};

	sort(arr, 10);

	for(int i=0; i<10; i++){
		cout << arr[i] << " ";
	}

	return 0;
}