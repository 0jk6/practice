#include <bits/stdc++.h>

using namespace std;
//1 2 4 8 9
bool isValid(vector<long long int> v, long long int cows, long long int mid){
	long long int prev = v[0];
	long long int count = 1;

	for(long long int i=1; i<v.size(); i++){
		if(v[i]-prev >= mid){
			count++;
			prev = v[i];
		}
		if(count >= cows)
			return true;
	}



	return false;
}

long long int solve(vector<long long int> v, long long int cows){
	long long int low = 0;
	long long int high = v[v.size()-1]-v[0]; //8
	long long int res;
	while(low <= high){
		long long int mid = low + (high - low)/2;
		
		if(isValid(v, cows, mid)){
			low = mid + 1;
			res = mid;
		}
		else{
			high = mid - 1;
		}
	}

	return res;
}



int main(){
	long long int t;
	cin >> t;
	while(t--){
		long long int n, cows;
		cin >> n >> cows;

		vector<long long int> v(n, 0);
		for(long long int i=0; i<n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		cout << solve(v, cows) << "\n";
	}

	return 0;
}