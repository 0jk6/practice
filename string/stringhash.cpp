#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//string rolling hash algorithm
/*
hash(s)=(s[0]+s[1]*p+s[2]*p^2+...+s[n−1]*p^n−1)%m
*/
long long compute_hash(string &s){
	const int p = 31; //prime number which is roughly equal to the length of the input string
	const int m = 1e9 + 9; //prime number which is large, so that the probability of collsion is very small 1/m

	long long hash_value = 0;
	long long p_pow = 1; //starting power, which goes on upto n-1

	for(char &c : s){
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m; //pre compute the power of p, for boosting performance
	}

	return hash_value;
}

vector<vector<int>> group_identical_strings(vector<string> &s){
	int n = s.size();

	//store the hashes with the index value
	vector<pair<long long, int>> hashes(n);

	for(int i=0; i<n; i++){
		hashes[i] = {compute_hash(s[i]), i};
	}

	//sort the hashes, these hashes will be sorted according to the first part of the pair
	sort(hashes.begin(), hashes.end());

	//group those equal hashes indices together
	vector<vector<int>> groups;

	for(int i=0; i<n; i++){
		//if i == 0, then we won't have a previous string hash
		//or if the current string's hash is not equal to previous string's hash

		if(i == 0 || hashes[i].first != hashes[i-1].first){
			groups.emplace_back();
		}

		groups.back().push_back(hashes[i].second);
	}

	return groups;
}

/*
Time complexity for naive solution will be O(nmlogn), O(nlogn) for sorting and them O(m) for comparision

Time complexity with the rolling hash method will be O(nm + nlogn), O(nlogn) for sorting and O(1) for comparision
Here the comparision time is reduced to O(1)
*/

int main(){
	vector<string> s = {"abcd", "abc", "bca", "abc", "abcd"};
	
	vector<vector<int>> v = group_identical_strings(s);

	for(auto it : v){
		for(auto jt : it){
			cout << s[jt] << " ";
		}

		cout << "\n";
	}

	return 0;
}