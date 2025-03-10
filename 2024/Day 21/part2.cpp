#include <cassert>
#include <iostream>
#include <set>
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
				if (0 <= i && i < (int)pad.size() && 0 <= j && j < (int)pad[0].size() && pad[i][j] != -1) {
					x = pad[i][j];
					return MOVEMENT;
				}
				else {
					return ERROR;
				}
			}
		}
	}
	assert(false);
}

const int M = 25;
const long long INF = 4e18;

long long dp[M + 2][11][11];

signed main() {
	freopen("input.txt", "r", stdin);

	for (int i = 1; i <= M + 1; i++) {
		const int N = (i == M + 1 ? 11 : 5);
		for (int j = 0; j < N; j++) {
			vector<vector<long long>> dist(5, vector<long long>(11, INF));
			dist[A][j] = 0;
			set<pair<long long, pair<int, int>>> pq;
			pq.insert({0, {A, j}});

			auto check = [&](int prv, int cur, long long d) {
				if (d < dist[prv][cur]) {
					pq.erase({dist[prv][cur], {prv, cur}});
					dist[prv][cur] = d;
					pq.insert({d, {prv, cur}});
				}
			};
			while (!pq.empty()) {
				long long d = pq.begin()->first;
				int prv = pq.begin()->second.first;
				int cur = pq.begin()->second.second;
				pq.erase(pq.begin());

				for (int k = 0; k < 5; k++) check(k, cur, d + dp[i - 1][prv][k]);

				if ((prv != A) && MOVEMENT == f2(prv, cur, (i == M + 1 ? num : dir))) check(prv, cur, d + 1);
			}
			for (int k = 0; k < N; k++) dp[i][j][k] = dist[A][k];
		}
	}

	string s;
	long long ans = 0;
	while (getline(cin, s)) {
		char prv = 'A';
		long long tot = 0;
		auto f = [](char t) { return t == 'A' ? 10 : t - '0'; };
		for (char c : s) {
			tot += dp[M + 1][f(prv)][f(c)] + 1;
			prv = c;
		}
		ans += tot * stoi(s.substr(0, 3));
	}

	cout << ans << '\n';
}
