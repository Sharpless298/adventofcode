#include <iostream>
#include <sstream>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	long long ans = 0;
	string s;
	stringstream ss;
	while (getline(cin, s)) {
		long long a1, b1, a2, b2, c1, c2;
		if (s.empty()) continue;

		ss.clear();
		ss.str(s);
		ss.ignore(12);
		ss >> a1;
		ss.ignore(4);
		ss >> a2;

		getline(cin, s);
		ss.clear();
		ss.str(s);
		ss.ignore(12);
		ss >> b1;
		ss.ignore(4);
		ss >> b2;

		getline(cin, s);
		ss.clear();
		ss.str(s);
		ss.ignore(9);
		ss >> c1;
		ss.ignore(4);
		ss >> c2;

		long long d = a1 * b2 - b1 * a2, dx = c1 * b2 - b1 * c2, dy = a1 * c2 - c1 * a2;
		if ((dx % d) != 0 || (dy % d) != 0) continue;
		ans += dx / d * 3 + dy / d;
	}

	cout << ans << '\n';
}
