#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}

	ifstream in(argv[1]);
	if (!in) {
		cerr << "Cannot open file: " << argv[1] << '\n';
		return 1;
	}

	vector<string> G;
	string s;
	while (in >> s) {
		G.push_back(s);
	}

	const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
	const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int n = (int)G.size(), m = (int)G[0].size(), ans = 0;
	vector<vector<int>> cnt(n, vector<int>(m, 0x3f3f3f3f));
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] != '@') {
				continue;
			}

			cnt[i][j] = 0;
			for (int k = 0; k < 8; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m) {
					cnt[i][j] += (G[ni][nj] == '@');
				}
			}
			if (cnt[i][j] < 4) {
				cnt[i][j] = 0x3f3f3f3f;
				q.push(i * n + j);
				ans++;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front() / n, y = q.front() % n;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				cnt[nx][ny]--;
				if (cnt[nx][ny] < 4) {
					q.push(nx * n + ny);
					cnt[nx][ny] = 0x3f3f3f3f;
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
