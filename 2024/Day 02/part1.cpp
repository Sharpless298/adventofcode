#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	int ans = 0;
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);

		vector<int> a;
		for (int x; ss >> x; a.push_back(x));

		bool ok = true;
		for (int i = 0; i < (int)a.size() - 1; i++) {
			int d = a[i] - a[i + 1];
			if (d >= 0 || d < -3) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans++;
			continue;
		}

		ok = true;
		for (int i = 0; i < (int)a.size() - 1; i++) {
			int d = a[i] - a[i + 1];
			if (d <= 0 || d > 3) {
				ok = false;
				break;
			}
		}
		if (ok) ans++;
	}

	cout << ans << '\n';
}
