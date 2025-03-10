#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<string> G;
	while (getline(cin, s)) G.push_back(s);

	int n = (int)G.size(), m = (int)G[0].size();
	int S, E;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 'S') S = i * m + j;
			if (G[i][j] == 'E') E = i * m + j;
		}
	}

	// > = 0, ^ = 1, < = 2, v = 3
	vector<int> d = {1, -m, -1, m};
	map<pair<int, int>, int> dis;
	map<pair<int, int>, vector<pair<int, int>>> mp;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
	dis[{S, 0}] = 0;
	pq.push({0, {S, 0}});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dis[cur.second] != cur.first) continue;

		for (int i = 0; i < 4; i++) {
			int nxt = cur.second.first + d[i];
			if (G[nxt / m][nxt % m] == '#') continue;

			int w = (cur.second.second == i ? 1 : 1001);
			if (dis.find({nxt, i}) == dis.end() || dis[cur.second] + w < dis[{nxt, i}]) {
				dis[{nxt, i}] = dis[cur.second] + w;
				pq.push({dis[{nxt, i}], {nxt, i}});
				mp[{nxt, i}].clear();
				mp[{nxt, i}].push_back(cur.second);
			}
			else if (dis[cur.second] + w == dis[{nxt, i}])
				mp[{nxt, i}].push_back(cur.second);
		}
	}

	set<int> st;
	queue<pair<int, int>> q;
	for (int i = 0; i < 4; i++) q.push({E, i});
	while (!q.empty()) {
		auto [u, dir] = q.front();
		q.pop();
		st.insert(u);

		for (pair<int, int> &p : mp[{u, dir}])
			if (!st.count(p.first)) q.push(p);
	}
	cout << st.size() - 1 << '\n';
}
