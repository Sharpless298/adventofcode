#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

vector<int> parent, sizes;

void init(int n) {
	parent.resize(n);
	sizes.resize(n);
	iota(parent.begin(), parent.end(), 0);
	fill(sizes.begin(), sizes.end(), 1);
}

int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a), b = find(b);

	if (a == b) return;

	if (sizes[a] > sizes[b]) swap(a, b);
	parent[a] = b;
	sizes[b] += sizes[a];
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<string> G;
	while (getline(cin, s)) G.push_back(s);

	int n = (int)G.size(), m = (int)G[0].size();
	init(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && G[i][j] == G[i + 1][j]) unite(i * m + j, (i + 1) * m + j);
			if (j + 1 < m && G[i][j] == G[i][j + 1]) unite(i * m + j, i * m + j + 1);
		}
	}

	auto check1 = [&](pair<int, int> a) { return a.first >= 0 && a.first < n && a.second >= 0 && a.second < m; };
	auto check2 = [&](pair<int, int> a, pair<int, int> b) {
		return check1(b) && G[a.first][a.second] == G[b.first][b.second];
	};

	vector<pair<int, int>> d = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
	vector<int> sides(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pair<int, int> cur = {i, j};
			for (int k = 0; k < 4; k++) {
				if (!check2(cur, cur + d[k]) && !check2(cur, cur + d[(k + 1) % 4])) sides[find(i * m + j)]++;
				if (check2(cur, cur + d[k]) && check2(cur, cur + d[(k + 1) % 4]) &&
					!check2(cur, cur + d[k] + d[(k + 1) % 4]))
					sides[find(i * m + j)]++;
			}
		}
	}

	int ans = 0;
	vector<bool> vis(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int f = find(i * m + j);
			if (!vis[f]) {
				vis[f] = true;
				ans += sizes[f] * sides[f];
			}
		}
	}

	cout << ans << '\n';
}
