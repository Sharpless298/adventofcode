#include <iostream>
#include <vector>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return {a.first + b.first, a.second + b.second};
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
	return {a.first - b.first, a.second - b.second};
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<string> G;
	while (getline(cin, s)) G.push_back(s);

	int ans = 0;
	int n = (int)G.size(), m = (int)G[0].size();
	vector<vector<pair<int, int>>> antennas(128);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (G[i][j] != '.') antennas[G[i][j]].push_back({i, j});

	auto check = [&](pair<int, int> a) {
		return a.first >= 0 && a.first < n && a.second >= 0 && a.second < m;
	};
	vector<vector<bool>> antinode(n, vector<bool>(m));
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < (int)antennas[i].size() - 1; j++) {
			for (int k = j + 1; k < (int)antennas[i].size(); k++) {
				if (j == k) continue;

				pair<int, int> v = antennas[i][j] - antennas[i][k];

				pair<int, int> x = antennas[i][j];
				while (check(x)) {
					if (!antinode[x.first][x.second]) antinode[x.first][x.second] = true, ans++;
					x = x + v;
				}
				x = antennas[i][k];
				while (check(x)) {
					if (!antinode[x.first][x.second]) antinode[x.first][x.second] = true, ans++;
					x = x - v;
				}
			}
		}
	}

	cout << ans << '\n';
}
