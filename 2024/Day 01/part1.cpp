#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	int x, y;
	vector<int> a, b;
	while (cin >> x >> y) a.push_back(x), b.push_back(y);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sum = 0;
	for (int i = 0; i < (int)a.size(); i++) sum += abs(a[i] - b[i]);

	cout << sum << '\n';
}
