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
		}
		else {
			for (int j = 0; j < (int)(s[i] - '0'); j++) a.push_back(id);
			id++;
		}
	}

	for (int i = 0, j = (int)a.size() - 1;;) {
		while (a[i] != -1) i++;
		while (a[j] == -1) j--;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	long long ans = 0;
	for (int i = 0; a[i] != -1; i++) ans += i * a[i];

	cout << ans << '\n';
}
