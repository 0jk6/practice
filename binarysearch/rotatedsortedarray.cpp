//find the element where the array is rotated

#include <iostream>

using namespace std;

int main(){
	int arr[8] = {11,12,15,18,2,5,6,8}; //this array is 4 times rotated

	int start = 0;
	int end = 7;
	int m = 0;
	while(start <= end){
		int mid = start + (end-start)/2;

		if(arr[mid]<arr[mid-1] && arr[mid+1]>arr[mid]){
			m = arr[mid];
			break;
		}
		else if(arr[mid]<arr[mid+1]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}

	cout << m << "\n";

	return 0;
}