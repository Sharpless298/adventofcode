#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> operator +(pair<int, int> a, pair<int, int> b) {
	return {a.first+b.first, a.second+b.second};
}

signed main() {
	freopen("input.txt", "r", stdin);
	
	char c;
	int a, b;
	vector<pair<int, int>> v;
	while(cin >> a >> c >> b) v.push_back({b, a});

	auto check = [&](pair<int, int> p) {
		return p.first>=0 && p.first<=70 && p.second>=0 && p.second<=70;
	};
	queue<pair<int, int>> q;
	vector<vector<bool>> vis(71, vector<bool>(71));
	vector<vector<bool>> corrupted(71, vector<bool>(71));
	vector<vector<int>> dis(71, vector<int>(71));
	for(int i=0; i<1024; i++) corrupted[v[i].first][v[i].second] = true;
	q.push({0, 0});
	vis[0][0] = true;
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		
		if(cur.first==70 && cur.second==70) break;
		for(pair<int, int> d : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
			pair<int, int> nxt = cur + d;
			if(check(nxt) && !corrupted[nxt.first][nxt.second] && !vis[nxt.first][nxt.second]) {
				vis[nxt.first][nxt.second] = true;
				dis[nxt.first][nxt.second] = dis[cur.first][cur.second] + 1;
				q.push(nxt);
			}
		}
	}

	cout << dis[70][70] << '\n';
}
