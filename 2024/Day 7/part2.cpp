#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool f;
long long x, ans;
vector<long long> a, power(19);

void DFS(int depth, long long cur) {
	if(f) return;

	if(depth == (int)a.size()) {
		if(cur == x) ans += x, f = true;
		return;
	}

	DFS(depth+1, cur*a[depth]);
	DFS(depth+1, cur+a[depth]);
	
	int cnt = 0;
	long long t = a[depth];
	while(t) t /= 10, cnt++;
	DFS(depth+1, cur*power[cnt]+a[depth]);
}

signed main() {
	freopen("input.txt", "r", stdin);
	
	power[0] = 1;
	for(int i=1; i<=18; i++)
		power[i] = power[i-1] * 10;

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

