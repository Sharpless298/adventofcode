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

	string s;
	long long ans = 0;
	while (getline(in, s)) {
		vector<long long> dp(13);
		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = min(i + 1, 12); j >= 1; j--) {
				dp[j] = max(dp[j], dp[j - 1] * 10 + s[i] - '0');
			}
		}
		ans += dp[12];
	}
	cout << ans << '\n';

	return 0;
}
