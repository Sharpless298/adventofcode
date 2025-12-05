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
	vector<long long> v;
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
		v.push_back(p.first);
		v.push_back(p.second);
	}

	long long x;
	vector<long long> q;
	while (in >> x) {
		v.push_back(x);
		q.push_back(x);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	vector<int> d(v.size() + 1);
	for (int i = 0; i < (int)a.size(); i++) {
		a[i].first = (int)(lower_bound(v.begin(), v.end(), a[i].first) - v.begin());
		a[i].second = (int)(lower_bound(v.begin(), v.end(), a[i].second) - v.begin());
		d[a[i].first]++;
		d[a[i].second + 1]--;
	}
	for (int i = 0; i < (int)v.size(); i++) {
		d[i + 1] += d[i];
	}

	int ans = 0;
	for (long long i : q) {
		i = (int)(lower_bound(v.begin(), v.end(), i) - v.begin());
		ans += (d[i] >= 1);
	}
	cout << ans << '\n';

	return 0;
}
