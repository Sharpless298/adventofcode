#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);
	
	string s;
	set<string> nodes;
	map<string, vector<string>> edges;
	set<pair<string, string>> pairs;
	while(getline(cin, s)) {
		string p = s.substr(0, 2), q = s.substr(3, 2);
	
		nodes.insert(p);
		nodes.insert(q);
		edges[p].push_back(q);
		edges[q].push_back(p);
		pairs.insert({p, q});
		pairs.insert({q, p});
	}

	int ans = 0;
	for(string a : nodes)
		for(string b : edges[a])
			for(string c : edges[b])
				if(pairs.count({a, c}) && (a[0]=='t' || b[0]=='t' || c[0]=='t')) ans++;
			
	cout << ans/6 << '\n';
}
