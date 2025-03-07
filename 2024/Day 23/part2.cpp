#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<string, vector<string>> edges;
set<pair<string, string>> pairs;
vector<string> v;

void rec(string a, int i, vector<string> clique) {
	if (i == (int)edges[a].size()) {
		if (clique.size() > v.size()) v = clique;
		return;
	}
	rec(a, i + 1, clique);

	for (string s : clique)
		if (!pairs.count({edges[a][i], s})) return;

	clique.push_back(edges[a][i]);
	rec(a, i + 1, clique);
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	set<string> nodes;
	while (getline(cin, s)) {
		string p = s.substr(0, 2), q = s.substr(3, 2);

		nodes.insert(p);
		nodes.insert(q);
		edges[p].push_back(q);
		edges[q].push_back(p);
		pairs.insert({p, q});
		pairs.insert({q, p});
	}

	for (string a : nodes) rec(a, 0, {a});

	string ans;
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i++) {
		if (i) ans += ",";
		ans += v[i];
	}
	cout << ans << '\n';
}
