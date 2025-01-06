#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
using namespace std;

int f(int a, string s, int b) {
	if(s == "AND") return a & b;
	if(s == "OR") return a | b;
	if(s == "XOR") return a ^ b;
	assert(false);
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	set<string> st;
	map<string, int> mp;
	while(getline(cin, s)) {
		if(s.empty()) break;
		st.insert(s.substr(0, 3));
		mp[s.substr(0, 3)] = s.back()-'0';
	}

	map<string, string> op;
	map<string, vector<string>> G, g;
	map<string, int> deg;
	while(getline(cin, s)) {
		stringstream ss(s);
		string a, b, c, d;
		ss >> a >> b >> c >> d >> d;
		op[d] = b;
		G[a].push_back(d);
		G[c].push_back(d);
		g[d].push_back(a);
		g[d].push_back(c);
		deg[d] = !st.count(a) + !st.count(c);
		if(deg[d] == 0) mp[d] = f(mp[a], b, mp[c]);
	}

	queue<string> q;
	for(auto p : deg) 
		if(p.second == 0) q.push(p.first);
	
	while(!q.empty()) {
		auto u = q.front(); q.pop();

		for(string v : G[u]) {
			deg[v]--;
			if(deg[v] == 0) {
				mp[v] = f(mp[g[v][0]], op[v], mp[g[v][1]]);
				q.push(v);
			}
		}
	}

	bool f = false;
	long long ans = 0, prod = 1;
	for(auto p : mp) {
		if(p.first == "z00") f = true;
		if(f) ans += p.second*prod, prod <<= 1;
	}
	cout << ans << '\n';
}
