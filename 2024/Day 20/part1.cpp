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
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (G[i][j] == '.' || G[i][j] == 'S' || G[i][j] == 'E') continue;

			if (G[i + 1][j] != '#' && G[i - 1][j] != '#') {
				if (max(d[i + 1][j], d[i - 1][j]) - min(d[i + 1][j], d[i - 1][j]) - 2 >= 100) ans++;
			}
			if (G[i][j + 1] != '#' && G[i][j - 1] != '#') {
				if (max(d[i][j + 1], d[i][j - 1]) - min(d[i][j + 1], d[i][j - 1]) - 2 >= 100) ans++;
			}
		}
	}

	cout << ans << '\n';
}
