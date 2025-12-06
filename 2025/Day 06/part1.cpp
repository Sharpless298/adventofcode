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
	vector<vector<int>> a;
	while (getline(in, s)) {
		if (s[0] == '*' || s[0] == '+') {
			break;
		}
		stringstream ss(s);
		int x;
		vector<int> v;
		while (ss >> x) {
			v.push_back(x);
		}
		a.push_back(v);
	}
	long long ans = 0;
	stringstream ss(s);
	for (int i = 0; i < (int)a[0].size(); i++) {
		char c;
		ss >> c;
		long long sum = (c == '+' ? 0 : 1LL);
		for (int j = 0; j < (int)a.size(); j++) {
			if (c == '+') {
				sum += a[j][i];
			} else {
				sum *= a[j][i];
			}
		}
		ans += sum;
	}
	cout << ans << '\n';

	return 0;
}
