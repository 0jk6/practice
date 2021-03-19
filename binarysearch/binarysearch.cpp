#include <iostream>

using namespace std;

int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int start = 0;
	int end = 9;

	int e = 4;
	int flag = 0;

	while(start <= end){
		int mid = start + (end-start)/2; //to prevent integer overflow
		if(arr[mid]==e){
			cout << "Found at index: " << mid << "\n";
			return 0;
		}
		else if(arr[mid]>e){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}

	if(flag == 1){
		cout << "Found\n";
	}
	else{
		cout << "Not Found\n";
	}

	return 0;
}