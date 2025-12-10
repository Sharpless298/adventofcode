#include <fstream>
#include <iostream>
#include <unordered_map>
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

	vector<int> v;
	vector<pair<int, int>> a;
	{
		char c;
		int x, y;
		while (in >> x >> c >> y) {
			x--, y--;
			v.push_back(x);
			v.push_back(y);
			a.push_back(make_pair(x, y));
		}
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < (int)a.size(); i++) {
		a[i].first = (int)(lower_bound(v.begin(), v.end(), a[i].first) - v.begin());
		a[i].second = (int)(lower_bound(v.begin(), v.end(), a[i].second) - v.begin());
	}

	unordered_map<int, vector<int>> rows, cols;
	for (auto &p : a) {
		rows[p.first].push_back(p.second);
		cols[p.second].push_back(p.first);
	}

	vector<vector<bool>> G(v.size(), vector<bool>(v.size()));
	for (auto &[x, vec] : rows) {
		sort(vec.begin(), vec.end());
		for (int y = vec[0]; y <= vec.back(); y++) {
			G[x][y] = true;
		}
	}
	for (auto &[y, vec] : cols) {
		sort(vec.begin(), vec.end());
		for (int x = vec[0]; x <= vec.back(); x++) {
			G[x][y] = true;
		}
	}

	vector<vector<int>> r(v.size() + 1, vector<int>(v.size() + 1));
	vector<vector<int>> c(v.size() + 1, vector<int>(v.size() + 1));
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			r[i][j + 1] = r[i][j] + G[i][j];
		}
	}
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			c[i + 1][j] = c[i][j] + G[i][j];
		}
	}

	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			if (G[i][j]) {
				continue;
			}
			bool L, R, U, D;
			L = (r[i][j] - r[i][0] > 0);
			R = (r[i][v.size()] - r[i][j] > 0);
			U = (c[i][j] - c[0][j] > 0);
			D = (c[v.size()][j] - c[i][j] > 0);
			G[i][j] = L && R && U && D;
		}
	}

	vector<vector<int>> pref(v.size() + 1, vector<int>(v.size() + 1));
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + G[i][j];
		}
	}

	long long ans = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i + 1; j < (int)a.size(); j++) {
			int mx_x = max(a[i].first, a[j].first), mx_y = max(a[i].second, a[j].second);
			int mn_x = min(a[i].first, a[j].first), mn_y = min(a[i].second, a[j].second);
			if (pref[mx_x + 1][mx_y + 1] - pref[mn_x][mx_y + 1] - pref[mx_x + 1][mn_y] +
					pref[mn_x][mn_y] ==
				(mx_x - mn_x + 1) * (mx_y - mn_y + 1)) {
				ans = max(ans, 1LL * (abs(v[a[i].first] - v[a[j].first]) + 1) *
								   (abs(v[a[i].second] - v[a[j].second]) + 1));
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
