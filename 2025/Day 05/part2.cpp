#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
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
	vector<pair<long long, long long>> a;
	while (getline(in, s)) {
		if (s.empty()) {
			break;
		}
		stringstream ss(s);
		pair<long long, long long> p;
		ss >> p.first;
		ss.ignore();
		ss >> p.second;
		a.push_back(p);
	}

	long long x;
	while (in >> x);

	sort(a.begin(), a.end());
	long long l = 0, r = -1, ans = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		assert(a[i].first <= a[i].second);
		if (a[i].first > r) {
			ans += r - l + 1;
			l = a[i].first;
		} 
		r = max(r, a[i].second);
	}
	ans += r - l + 1;
	cout << ans << '\n';

	return 0;
}
