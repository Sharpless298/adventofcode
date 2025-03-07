#include <iostream>
#include <map>
#include <queue>
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

		set<int> st;
		for (int i : a) st.insert(i);

		bool ok = true;
		set<int> st2;
		map<int, int> deg;
		for (int i : a) {
			for (int j : G[i]) {
				if (st.count(j)) deg[j]++;
				if (st2.count(j)) ok = false;
			}
			st2.insert(i);
		}
		if (ok) continue;

		queue<int> q;
		for (int i : a)
			if (deg[i] == 0) q.push(i);

		vector<int> order;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			order.push_back(u);
			for (int v : G[u])
				if (--deg[v] == 0) q.push(v);
		}

		ans += order[order.size() / 2];
	}

	cout << ans << '\n';
}
