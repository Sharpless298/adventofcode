#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> a;
bool DFS(int p, long long cur) {
	if (p < 0) {
		cout << cur << '\n';
		return true;
	}

	for (int i = 0; i < 8; i++) {
		long long A = ((cur << 3) | i), B = 0, C = 0;
		int idx = 0;
		long long combo, w;
		while (idx < (int)a.size()) {
			if (a[idx + 1] <= 3)
				combo = a[idx + 1];
			else if (a[idx + 1] == 4)
				combo = A;
			else if (a[idx + 1] == 5)
				combo = B;
			else
				combo = C;

			if (a[idx] == 0)
				A >>= combo;
			else if (a[idx] == 1)
				B ^= a[idx + 1];
			else if (a[idx] == 2)
				B = combo & 7;
			else if (a[idx] == 3)
				idx = (A != 0 ? a[idx + 1] - 2 : idx);
			else if (a[idx] == 4)
				B ^= C;
			else if (a[idx] == 5) {
				w = combo & 7;
				break;
			} else if (a[idx] == 6)
				B = A >> combo;
			else if (a[idx] == 7)
				C = A >> combo;
			idx += 2;
		}
		if (w == a[p] && DFS(p - 1, (cur << 3) | i)) return true;
	}
	return false;
}

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	getline(cin, s);
	getline(cin, s);
	getline(cin, s);

	cin.ignore();
	getline(cin, s);
	stringstream ss(s);
	ss.ignore(8);
	int x;
	while (ss >> x) {
		ss.ignore(1);
		a.push_back(x);
	}

	DFS((int)a.size() - 1, 0);
}
