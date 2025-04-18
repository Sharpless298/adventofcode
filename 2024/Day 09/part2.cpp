#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);
	string s;
	cin >> s;

	vector<int> a;
	for (int i = 0, id = 0; i < (int)s.size(); i++) {
		if (i & 1) {
			for (int j = 0; j < (int)(s[i] - '0'); j++) a.push_back(-1);
		} else {
			for (int j = 0; j < (int)(s[i] - '0'); j++) a.push_back(id);
			id++;
		}
	}

	for (int i, j = (int)a.size() - 1;;) {
		while (a[j] == -1) j--;
		i = j;
		while (a[i] == a[j]) {
			i--;
			if (i < 0) break;
		}
		if (i < 0) break;

		for (int k = 0; k <= i - (j - i) + 1; k++) {
			bool ok = true;
			for (int x = k; x < k + (j - i); x++)
				if (a[x] != -1) ok = false;

			if (ok) {
				for (int x = k; x < k + (j - i); x++, j--) swap(a[x], a[j]);
			}
		}
		j = i;
	}

	long long ans = 0;
	for (int i = 0; i < (int)a.size(); i++)
		if (a[i] != -1) ans += i * a[i];

	cout << ans << '\n';
}
