#include <iostream>

using namespace std;

int totalPaths = 0;

void findPaths(int i, int j, int n, int m, string osf){
	if(i==n-1 && j==m-1){
		totalPaths += 1;
		cout << osf << "\n";
		return;
	}

	if(i>=n || j>=m)
		return;

	findPaths(i, j+1, n, m, osf+"R");
	findPaths(i+1, j, n, m, osf+"D");
}


int main(){
	int m, n;
	cin >> m >> n;

	findPaths(0, 0, m, n, "");
	cout << "Total paths: " << totalPaths << "\n";
	return 0;
}