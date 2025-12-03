#include <fstream>
#include <iostream>
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

	string s;
	int ans = 0;
	while (getline(in, s)) {
		int mx = -1, mx2 = -1;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] - '0' > mx) {
				mx = s[i] - '0';
				mx2 = -1;
			} else {
				mx2 = max(mx2, s[i] - '0');
			}
		}
		ans += mx * 10 + mx2;
	}
	cout << ans << '\n';

	return 0;
}
