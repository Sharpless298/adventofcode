#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
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

	string str;
	set<int> s;
	getline(in, str);
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == 'S') {
			s.insert(i);
			break;
		}
	}

	vector<long long> cnt(str.size());
	cnt[*s.begin()] = 1;
	while (getline(in, str)) {
		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] == '^' && s.count(i)) {
				cnt[i - 1] += cnt[i];
				cnt[i + 1] += cnt[i];
				cnt[i] = 0;
				s.erase(i);
				s.insert(i - 1);
				s.insert(i + 1);
			}
		}
	}
	cout << accumulate(cnt.begin(), cnt.end(), 0LL) << '\n';

	return 0;
}
