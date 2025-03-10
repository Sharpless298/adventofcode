#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

int n, m;
pair<int, int> S, E;

bool check(pair<int, int> a) {
	return a.first >= 0 && a.first < n && a.second >= 0 && a.second < m;
}

signed main() {
	freopen("input.txt", "r", stdin);

	vector<string> G;
	string s;
	while (getline(cin, s)) G.push_back(s);

	n = (int)G.size(), m = (int)G[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 'S') S = {i, j};
			if (G[i][j] == 'E') E = {i, j};
		}
	}

	vector<vector<int>> d(n, vector<int>(m));
	vector<vector<bool>> vis(n, vector<bool>(m));
	queue<pair<pair<int, int>, int>> q;
	q.push({S, 0});
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		vis[cur.first.first][cur.first.second] = true;
		d[cur.first.first][cur.first.second] = cur.second;
		for (pair<int, int> p : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
			pair<int, int> nxt = cur.first + p;
			if (check(nxt) && G[nxt.first][nxt.second] != '#' && !vis[nxt.first][nxt.second])
				q.push({nxt, cur.second + 1});
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == '#') continue;

			for (int k = -20; k <= 20; k++) {
				int t = 20 - abs(k);
				for (int l = -t; l <= t; l++) {
					if (k == 0 && l == 0) continue;
					if (check({i + k, j + l}) && G[i + k][j + l] != '#') {
						ans += (d[i][j] - d[i + k][j + l] - (abs(k) + abs(l))) >= 100;
					}
				}
			}
		}
	}

	cout << ans << '\n';
}
