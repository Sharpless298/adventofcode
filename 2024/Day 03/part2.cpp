#include <iostream>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	long long ans = 0;
	string s;
	bool f = true;
	while (getline(cin, s)) {
		for (int i = 0; i < (int)s.size(); i++) {
			if (s.substr(i, 4) == "do()") f = true;
			if (s.substr(i, 7) == "don't()") f = false;
			if (s.substr(i, 4) == "mul(" && f) {
				i += 4;
				int a = 0;
				while (s[i] >= '0' && s[i] <= '9') a = a * 10 + s[i] - '0', i++;
				if (s[i] != ',') continue;
				i++;
				int b = 0;
				while (s[i] >= '0' && s[i] <= '9') b = b * 10 + s[i] - '0', i++;
				if (s[i] != ')') continue;

				ans += a * b;
			}
		}
	}

	cout << ans << '\n';
}
