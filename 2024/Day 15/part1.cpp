#include <iostream>
#include <map>
#include <vector>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
vector<string> G;
map<char, int> dir;

void move(pair<int, int> cur, int t) {
	pair<int, int> nxt = cur + d[t];
	if (G[nxt.first][nxt.second] == 'O') move(nxt, t);
	if (G[nxt.first][nxt.second] == '.') swap(G[cur.first][cur.second], G[nxt.first][nxt.second]);
}

signed main() {
	freopen("input.txt", "r", stdin);

	dir['>'] = 0, dir['^'] = 1, dir['<'] = 2, dir['v'] = 3;

	string s;
	while (getline(cin, s)) {
		if (s.empty()) break;
		G.push_back(s);
	}

	string moves;
	while (getline(cin, s)) moves += s;

	int n = (int)G.size(), m = (int)G[0].size();
	pair<int, int> cur;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == '@') {
				cur = {i, j};
				break;
			}
		}
	}

	for (char c : moves) {
		move(cur, dir[c]);
		if (G[cur.first][cur.second] != '@') cur = cur + d[dir[c]];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (G[i][j] == 'O') ans += 100 * i + j;

	cout << ans << '\n';
}
