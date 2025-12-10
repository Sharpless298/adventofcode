#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "z3++.h"
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

	long long ans = 0;
	string s;
	while (getline(in, s)) {
		stringstream ss(s);
		string t;
		ss >> t;

		vector<int> b;
		vector<vector<int>> tmp;
		while (ss >> t) {
			int c;
			stringstream st(t);
			st.ignore();
			if (t[0] == '{') {
				while (st >> c) {
					st.ignore();
					b.push_back(c);
				}
			} else {
				vector<int> v;
				while (st >> c) {
					st.ignore();
					v.push_back(c);
				}
				tmp.push_back(v);
			}
		}
		vector<vector<int>> a(tmp.size(), vector<int>(b.size()));
		for (int i = 0; i < (int)tmp.size(); i++) {
			for (int j = 0; j < (int)tmp[i].size(); j++) {
				a[i][tmp[i][j]] = 1;
			}
		}

		z3::context c;
		z3::optimize opt(c);
		vector<z3::expr> x;
		for (int i = 0; i < (int)a.size(); i++) {
			x.push_back(c.int_const(("x" + to_string(i)).c_str()));
			opt.add(x[i] >= 0);
		}
		for (int i = 0; i < (int)b.size(); i++) {
			z3::expr sum = c.int_val(0);
			for (int j = 0; j < (int)a.size(); j++) {
				sum = sum + a[j][i] * x[j];
			}
			opt.add(sum == b[i]);
		}
		z3::expr total = c.int_val(0);
		for (int i = 0; i < (int)a.size(); i++) {
			total = total + x[i];
		}
		opt.minimize(total);
		if (opt.check() == z3::sat) {
			z3::model m = opt.get_model();
			z3::expr total_val = m.eval(total, true);
			ans += stoll(total_val.to_string());
		}
	}
	cout << ans << '\n';

	return 0;
}
