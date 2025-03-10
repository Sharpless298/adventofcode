#include <iostream>
#include <queue>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<vector<int>> G;
	while (getline(cin, s)) {
		vector<int> v;
		for (char c : s) v.push_back(c - '0');
		G.push_back(v);
	}

	int n = (int)G.size(), m = (int)G[0].size(), ans = 0;

	auto check = [&](pair<int, int> a) { return a.first >= 0 && a.first < n && a.second >= 0 && a.second < m; };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 0) {
				queue<pair<int, int>> q;
				vector<vector<bool>> vis(n, vector<bool>(m));
				q.push({i, j});
				vis[i][j] = true;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					if (G[cur.first][cur.second] == 9) {
						ans++;
						continue;
					}

					for (auto d : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
						pair<int, int> nxt = cur;
						nxt = {cur.first + d.first, cur.second + d.second};
						if (check(nxt) && !vis[nxt.first][nxt.second] &&
							G[nxt.first][nxt.second] == G[cur.first][cur.second] + 1)
							vis[nxt.first][nxt.second] = true, q.push(nxt);
					}
				}
			}
		}
	}

	cout << ans << '\n';
}
