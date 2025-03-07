#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

long long ans = 0;
string s;
vector<long long> power(128), h, pref, temp;
vector<string> towel;

long long DFS(int sz, long long sum) {
	if (sz == (int)s.size()) return 1;
	if (temp[sz] == -1) return 0;
	if (temp[sz] > 0) return temp[sz];

	long long res = 0;
	for (int i = 0; i < (int)towel.size(); i++) {
		int p = sz + (int)towel[i].size();
		long long q = (sum * power[towel[i].size()] + h[i]) % MOD;
		if (p <= (int)s.size() && q == pref[p]) res += DFS(p, q);
	}
	temp[sz] = res ? res : -1;
	return res;
}

signed main() {
	freopen("input.txt", "r", stdin);

	power[0] = 1;
	for (int i = 0; i < 100; i++) power[i + 1] = power[i] * 31 % MOD;

	getline(cin, s);
	s += ',';
	string t;
	stringstream ss(s);
	while (getline(ss, t, ' ')) {
		t.pop_back();
		towel.push_back(t);
	}
	cin.ignore();

	h.resize(towel.size());
	for (int i = 0; i < (int)towel.size(); i++) {
		h[i] = 0;
		for (int j = 0; j < (int)towel[i].size(); j++) h[i] = (h[i] * 31 + towel[i][j] - 'a') % MOD;
	}
	temp.resize(128);
	while (getline(cin, s)) {
		pref.resize(s.size() + 1);
		pref[0] = 0;
		for (int i = 0; i < (int)s.size(); i++) pref[i + 1] = (pref[i] * 31 + s[i] - 'a') % MOD;
		fill(temp.begin(), temp.end(), 0);
		ans += DFS(0, 0);
	}
	cout << ans << '\n';
}
