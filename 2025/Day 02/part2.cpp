#include <fstream>
#include <sstream>
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

	vector<long long> power(19);
	power[0] = 1;
	for (int i = 0; i < 18; i++) {
		power[i + 1] = power[i] * 10;
	}
	auto f = [](long long z) {
		int ret = 0;
		while (z) {
			ret++;
			z /= 10;
		}
		return ret;
	};

	string s;
	getline(in, s);
	s.push_back(',');
	stringstream ss(s);
	char c;
	long long x, y;
	long long ans = 0;
	while (ss >> x >> c >> y) {
		for (long long i = x; i <= y; i++) {
			int j = f(i);
			for (int k = 1; k < j; k++) {
				if (j % k == 0) {
					bool ok = true;
					long long cur = i, tmp = i % power[k];
					for (int l = 0; l < (j / k) - 1; l++) {
						cur /= power[k];
						if (cur % power[k] != tmp) {
							ok = false;
							break;
						}
					}
					if (ok) {
						ans += i;
						break;
					}
				}
			}
		}
		ss.ignore();
	}
	cout << ans << '\n';

	return 0;
}
