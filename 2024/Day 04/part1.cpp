#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	vector<string> a;
	while (cin >> s) a.push_back(s);

	int n = (int)a.size(), m = (int)s.size(), ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'X') {
				for (int k = 0; k < 8; k++) {
					int ni = i, nj = j;
					string t;
					for (int l = 0; l < 3; l++) {
						ni += dx[k], nj += dy[k];
						if (ni >= 0 && ni < n && nj >= 0 && nj < m) t += a[ni][nj];
					}
					if (t == "MAS") ans++;
				}
			}
		}
	}

	cout << ans << '\n';
}
