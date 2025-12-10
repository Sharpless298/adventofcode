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

	char c;
	int x, y;
	vector<pair<int, int>> a;
	while (in >> x >> c >> y) {
		a.push_back(make_pair(x, y));
	}

	long long ans = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i + 1; j < (int)a.size(); j++) {
			ans = max(ans, 1LL * (abs(a[i].first - a[j].first) + 1) *
							   (abs(a[i].second - a[j].second) + 1));
		}
	}
	cout << ans << '\n';

	return 0;
}
