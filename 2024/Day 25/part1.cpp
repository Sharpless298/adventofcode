#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<vector<int>> a, b;
	while (getline(cin, s)) {
		if (s.empty()) continue;

		vector<int> t(5);
		for (int i = 0; i < 5; i++) {
			getline(cin, s);
			for (int j = 0; j < (int)s.size(); j++) t[j] += (s[j] == '#');
		}

		getline(cin, s);
		if (s[0] == '#')
			a.push_back(t);
		else
			b.push_back(t);
	}

	int ans = 0;
	for (vector<int> &p : a) {
		for (vector<int> &q : b) {
			bool ok = true;
			for (int i = 0; i < 5; i++)
				if (p[i] + q[i] > 5) ok = false;
			ans += ok;
		}
	}

	cout << ans << '\n';
}
