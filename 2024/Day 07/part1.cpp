#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool f;
long long x, ans;
vector<long long> a;

void DFS(int depth, long long cur) {
	if(f) return;

	if(depth == (int)a.size()) {
		if(cur == x) ans += x, f = true;
		return;
	}

	DFS(depth+1, cur*a[depth]);
	DFS(depth+1, cur+a[depth]);
}

signed main() {
	freopen("input.txt", "r", stdin);
	
	string s;
	while(getline(cin, s)) {
		stringstream ss(s);

		ss >> x;
		char c;
		ss >> c;

		int t;
		a.clear();
		while(ss >> t) a.push_back(t);
		
		f = false;
		DFS(1, a[0]);
	}

	cout << ans << '\n';
}
