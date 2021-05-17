#include <iostream>

using namespace std;

void mergesort(int arr[], int l, int r){
	if(l < r){
		int mid = l + (r-l)/2;

		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

void merge(int arr[], int l, int mid, int r){
	int i = l;
	int j = mid+1;
	int k = l;

	while(i <= mid && j<=r){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=r){
			b[k]=a[j];
			k++;
			j++;
		}
	}
	else{
		while(i <= mid){
			b[k]=a[i];
			k++;
			i++;
		}
	}

	for(k = l; k<=r; k++){
		a[k]=b[k];
	}
	
}

int main(){

}