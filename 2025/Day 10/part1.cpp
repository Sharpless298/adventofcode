#include <fstream>
#include <iostream>
#include <sstream>
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

	int ans = 0;
	string s;
	while (getline(in, s)) {
		stringstream ss(s);
		string t;
		ss >> t;
		int x = 0;
		for (int i = 1; i < (int)t.size() - 1; i++) {
			if (t[i] == '#') {
				x |= (1 << (i - 1));
			}
		}
		vector<int> a;
		while (ss >> t) {
			if (t[0] == '{') {
				break;
			}
			int y = 0;
			stringstream st(t);
			st.ignore();
			int c;
			while (st >> c) {
				st.ignore();
				y |= (1 << c);
			}
			a.push_back(y);
		}
		int mn = 0x3f3f3f3f;
		for (int i = 0; i < (1 << a.size()); i++) {
			int y = 0;
			for (int j = 0; j < 32; j++) {
				if (i & (1 << j)) {
					y ^= a[j];
				}
			}
			if (x == y) {
				mn = min(mn, __builtin_popcount(i));
			}
		}
		ans += mn;
	}
	cout << ans << '\n';

	return 0;
}
