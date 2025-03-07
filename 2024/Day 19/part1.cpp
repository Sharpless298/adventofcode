#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

bool f;
int ans = 0;
string s;
vector<long long> power(101), h, pref;
vector<string> towel;

void DFS(int sz, long long sum) {
	if (sz == (int)s.size() && sum == pref[s.size()]) {
		ans++;
		f = true;
		return;
	}

	for (int i = 0; !f && i < (int)towel.size(); i++) {
		int p = sz + (int)towel[i].size();
		long long q = (sum * power[towel[i].size()] + h[i]) % MOD;
		if (p <= (int)s.size() && q == pref[p]) DFS(p, q);
	}
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
	while (getline(cin, s)) {
		pref.resize(s.size() + 1);
		pref[0] = 0;
		for (int i = 0; i < (int)s.size(); i++) pref[i + 1] = (pref[i] * 31 + s[i] - 'a') % MOD;
		f = false;
		DFS(0, 0);
	}
	cout << ans << '\n';
}
