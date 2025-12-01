#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	vector<pair<int, int>> d{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	string s;
	vector<string> G;
	while (getline(cin, s)) G.push_back(s);

	int n = (int)G.size(), m = (int)G[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m));

	pair<int, int> cur;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (G[i][j] == '^') cur = {i, j};

	auto check = [&](pair<int, int> a) {
		return a.first >= 0 && a.first < n && a.second >= 0 && a.second < m;
	};
	int f = 0, ans = 0;
	while (1) {
		if (!vis[cur.first][cur.second]) {
			vis[cur.first][cur.second] = true;
			ans++;
		}
		pair<int, int> nxt = {cur.first + d[f].first, +cur.second + d[f].second};

		if (!check(nxt)) break;

		if (G[nxt.first][nxt.second] == '#')
			f = (f + 1) % 4;
		else
			cur = nxt;
	}

	cout << ans << '\n';
}
