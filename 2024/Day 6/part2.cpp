#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	vector<pair<int, int>> d{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	string s;
	vector<string> G;
	while(getline(cin, s)) G.push_back(s);
	
	int n = (int)G.size(), m = (int)G[0].size();
	vector<vector<int>> vis(n, vector<int>(m));

	pair<int, int> start;
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) 
			if(G[i][j] == '^') start = {i, j};

	auto check = [&](pair<int, int> a) {
		return a.first>=0 && a.first<n && a.second>=0 && a.second<m;
	};
	int ans = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int f = 0;
			pair<int, int> cur = start;
			for(int k=0; k<n; k++)
				for(int l=0; l<m; l++)
					vis[k][l] = -1;
			while(1) {
				if(vis[cur.first][cur.second] == -1) 
					vis[cur.first][cur.second] = f; 
				else {
					if(f == vis[cur.first][cur.second]) {
						ans++;
						break;
					}
				}
				pair<int, int> nxt = {cur.first+d[f].first, + cur.second+d[f].second};

				if(!check(nxt)) break;
				
				if(G[nxt.first][nxt.second]=='#' || (nxt.first==i && nxt.second==j)) f = (f+1)%4;
				else cur = nxt;
			}
		}
	}
	
	cout << ans << '\n';
}

