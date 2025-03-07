#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	long long x;
	vector<long long> a;
	while (cin >> x) a.push_back(x);

	auto f = [&](long long t) {
		int cnt = 0;
		while (t) t /= 10, cnt++;
		return cnt;
	};
	for (int i = 0; i < 25; i++) {
		for (int j = (int)a.size() - 1; j >= 0; j--) {
			int d = f(a[j]);

			if (a[j] == 0)
				a[j] = 1;
			else if (d % 2 == 0) {
				long long t = 1;
				for (int k = 0; k < d / 2; k++) t *= 10;
				a.push_back(a[j] / t);
				a[j] %= t;
			} else
				a[j] *= 2024;
		}
	}

	cout << a.size() << '\n';
}
