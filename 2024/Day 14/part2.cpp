#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	vector<int> x, y, vx, vy;
	string s;
	stringstream ss;
	while (getline(cin, s)) {
		int a, b, c, d;

		ss.clear();
		ss.str(s);
		ss.ignore(2);
		ss >> a;
		ss.ignore(1);
		ss >> b;
		x.push_back(a), y.push_back(b);

		ss.ignore(3);
		ss >> c;
		ss.ignore(1);
		ss >> d;
		vx.push_back(c), vy.push_back(d);
	}

	for (int t = 1;; t++) {
		vector<vector<char>> G(103, vector<char>(101, '.'));
		for (int j = 0; j < (int)x.size(); j++) {
			int tx = ((x[j] + vx[j] * t) % 101 + 101) % 101;
			int ty = ((y[j] + vy[j] * t) % 103 + 103) % 103;
			G[ty][tx] = '#';
		}

		for (int i = 0; i < 103; i++) {
			for (int j = 0; j < 93; j++) {
				bool ok = true;
				for (int k = 0; k < 8; k++) {
					if (G[i][j + k] != '#') {
						ok = false;
						break;
					}
				}
				if (ok) {
					cout << t << '\n';
					return 0;
				}
			}
		}
	}
}
