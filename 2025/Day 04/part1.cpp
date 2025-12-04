#include <fstream>
#include <iostream>
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] != '@') {
				continue;
			}

			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m) {
					cnt += (G[ni][nj] == '@');
				}
			}
			ans += (cnt < 4);
		}
	}
	cout << ans << '\n';

	return 0;
}
