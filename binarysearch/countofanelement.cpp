//count of an element in a sorted array

#include <iostream>

using namespace std;

int main(){

	int arr[7] = {2,4,10,10,10,18,20};

	int target = 10;
	int start = 0;
	int end = 6;
	int res = -1;

	int firstIndex = -1;
	int lastIndex = -1;

	//find the first occurrence
	while(start <= end){
		int mid = start + (end-start)/2;

		if(target == arr[mid]){
			res = mid; //store the index in the res
			end = mid-1;
		}
		else if(target < arr[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	//update the first occurrence index in firstIndex
	firstIndex = res;

	//find the last occurence
	start = 0;
	end = 6;

	while(start <= end){
		int mid = start + (end-start)/2;

		if(target == arr[mid]){
			res = mid;
			start = mid+1;
		}
		else if(target < arr[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}

	lastIndex = res;

	if(lastIndex==-1 && firstIndex==-1)
		cout << "Element not found in the array\n";
	else
		cout << "Count: " << lastIndex - firstIndex + 1 << "\n";

	return 0;
}