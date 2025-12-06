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

	string s;
	vector<string> a;
	while (getline(in, s)) {
		reverse(s.begin(), s.end());
		a.push_back(s);
	}

	long long ans = 0;
	vector<int> v;
	for (int i = 0; i < (int)a[0].size(); i++) {
		bool f = false;
		int c = 0;
		for (int j = 0; j < (int)a.size(); j++) {
			if (isdigit(a[j][i])) {
				c = c * 10 + a[j][i] - '0';
				f = true;
			}
		}
		if (f) {
			v.push_back(c);
		}
		if (a[a.size() - 1][i] == '+' || a[a.size() - 1][i] == '*') {
			long long sum = (a[a.size() - 1][i] == '+' ? 0 : 1);
			for (int x : v) {
				if (a[a.size() - 1][i] == '+') {
					sum += x;
				} else {
					sum *= x;
				}
			}
			v.clear();
			ans += sum;
		}
	}
	cout << ans << '\n';

	return 0;
}
