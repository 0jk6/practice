#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int target){
	while(low <= high){
		int mid = low + (high-low)/2;

		if(arr[mid]==target){
			return mid;
		}
		else if(arr[mid]>=arr[low]){
			//case 1, left side of the array is sorted
			if(target >= arr[low] && target <= arr[mid]){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		else{
			//case 2, right side of the array is sorted
			if(target >= arr[mid] && target <= arr[high]){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}

	}
	return -1;
}

int main(){
	int n, target;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	cin >> target;

	cout << "Found at index: " << binarySearch(arr, 0, n-1, target);

	return 0;
}