#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<int> v;
	vector<vector<int>> G;
	while(getline(cin, s)) {
		for(char c : s) v.push_back(c-'0');
		G.push_back(v);
	}

	
}
