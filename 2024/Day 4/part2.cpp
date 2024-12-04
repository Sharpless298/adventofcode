#include <iostream>
#include <vector>
using namespace std;

bool check(int i, int j, vector<string> &a) {
	return ((a[i+1][j+1]=='M' && a[i-1][j-1]=='S') || (a[i+1][j+1]=='S' && a[i-1][j-1]=='M')) && 
		   ((a[i+1][j-1]=='M' && a[i-1][j+1]=='S') || (a[i+1][j-1]=='S' && a[i-1][j+1]=='M'));
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<string> a;
	while(cin >> s) a.push_back(s);

	int n = (int)a.size(), m = (int)s.size(), ans = 0;
	for(int i=1; i<n-1; i++)
		for(int j=1; j<m-1; j++)
			if(a[i][j]=='A' && check(i, j, a)) ans++;

	cout << ans << '\n';
}
