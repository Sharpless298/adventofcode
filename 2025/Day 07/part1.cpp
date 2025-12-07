#include <fstream>
#include <iostream>
#include <set>
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

	int ans = 0;
	while (getline(in, str)) {
		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] == '^' && s.count(i)) {
				s.erase(i);
				s.insert(i - 1);
				s.insert(i + 1);
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
