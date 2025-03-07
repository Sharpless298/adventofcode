#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

map<int, vector<int>> G;

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	while (getline(cin, s)) {
		if (s.empty()) break;

		stringstream ss(s);
		char c;
		int a, b;
		ss >> a >> c >> b;
		G[a].push_back(b);
	}

	int ans = 0;
	while (getline(cin, s)) {
		stringstream ss(s);
		vector<int> a;

		int x;
		while (ss >> x) {
			char c;
			ss >> c;
			a.push_back(x);
		}

		bool ok = true;
		set<int> st;
		for (int i : a) {
			if (!ok) break;
			for (int j : G[i]) {
				if (st.count(j)) {
					ok = false;
					break;
				}
			}
			st.insert(i);
		}
		if (ok) ans += a[a.size() / 2];
	}

	cout << ans << '\n';
}
