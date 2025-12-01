#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> num = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}, {-1, 0, 10}};

const int U = 0, L = 1, D = 2, R = 3, A = 4;
vector<vector<int>> dir = {{-1, U, A}, {L, D, R}};

vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

const char MOVEMENT = '$', ERROR = '#';
char f2(int mv, int &x, vector<vector<int>> &pad) {
	for (int i = 0; i < (int)pad.size(); i++) {
		for (int j = 0; j < (int)pad[0].size(); j++) {
			if (pad[i][j] == x) {
				i += dirs[mv].first;
				j += dirs[mv].second;
				if (0 <= i && i < (int)pad.size() && 0 <= j && j < (int)pad[0].size() &&
					pad[i][j] != -1) {
					x = pad[i][j];
					return MOVEMENT;
				} else {
					return ERROR;
				}
			}
		}
	}
	assert(false);
}

char f1(int mv, int t, vector<int> &v) {
	if (mv == A) {
		if (t == 2) return v[2] == 10 ? 'A' : (char)('0' + v[2]);
		return f1(v[t], t + 1, v);
	}
	return f2(mv, v[t], (t == 2 ? num : dir));
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	long long ans = 0;
	while (getline(cin, s)) {
		bool vis[5][5][5][11] = {false};
		int dp[5][5][5][11] = {0};
		vis[0][A][A][10] = true;
		dp[0][A][A][10] = 0;
		queue<vector<int>> q;
		q.push({0, A, A, 10});
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (cur[0] == 4) {
				ans += dp[4][cur[1]][cur[2]][cur[3]] * stoi(s.substr(0, 3));
				break;
			}

			for (int i = 0; i < 5; i++) {
				auto nxt = cur;
				nxt.erase(nxt.begin());

				char res = f1(i, 0, nxt);
				if (res == ERROR) continue;
				if (res != MOVEMENT && res != s[cur[0]]) continue;

				int t = cur[0] + (res != MOVEMENT);
				if (!vis[t][nxt[0]][nxt[1]][nxt[2]]) {
					vis[t][nxt[0]][nxt[1]][nxt[2]] = true;
					dp[t][nxt[0]][nxt[1]][nxt[2]] = dp[cur[0]][cur[1]][cur[2]][cur[3]] + 1;
					q.push({t, nxt[0], nxt[1], nxt[2]});
				}
			}
		}
	}

	cout << ans << '\n';
}
