#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

signed main() {
	freopen("input.txt", "r", stdin);

	char c;
	int a, b;
	vector<pair<int, int>> v;
	while (cin >> a >> c >> b) v.push_back({b, a});

	auto check = [&](pair<int, int> p) { return p.first >= 0 && p.first <= 70 && p.second >= 0 && p.second <= 70; };
	vector<vector<bool>> corrupted(71, vector<bool>(71));
	for (int i = 0; i < (int)v.size(); i++) {
		queue<pair<int, int>> q;
		vector<vector<bool>> vis(71, vector<bool>(71));
		q.push({0, 0});
		vis[0][0] = corrupted[v[i].first][v[i].second] = true;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (pair<int, int> d : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
				pair<int, int> nxt = cur + d;
				if (check(nxt) && !corrupted[nxt.first][nxt.second] && !vis[nxt.first][nxt.second]) {
					vis[nxt.first][nxt.second] = true;
					q.push(nxt);
				}
			}
		}
		if (!vis[70][70]) {
			cout << v[i].second << ',' << v[i].first << '\n';
			break;
		}
	}
}
