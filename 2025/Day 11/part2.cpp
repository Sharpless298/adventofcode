#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
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

	unordered_map<string, vector<string>> G;
	unordered_map<string, int> deg;
	string s;
	while (getline(in, s)) {
		string t = s.substr(0, 3);
		stringstream ss(s.substr(5));
		string x;
		deg[t];
		while (ss >> x) {
			G[t].push_back(x);
			deg[x]++;
		}
	}

	queue<string> q;
	for (auto &[a, b] : deg) {
		if (b == 0) {
			q.push(a);
		}
	}

	unordered_map<string, array<long long, 4>> dp;
	dp["svr"][0] = 1;
	while (!q.empty()) {
		string u = q.front();
		q.pop();
		for (string v : G[u]) {
			if (v == "dac") {
				dp[v][1] += dp[u][0];
				dp[v][3] += dp[u][2];
			} else if (v == "fft") {
				dp[v][2] += dp[u][0];
				dp[v][3] += dp[u][1];
			} else {
				for (int i = 0; i < 4; i++) {
					dp[v][i] += dp[u][i];
				}
			}
			deg[v]--;
			if (deg[v] == 0) {
				q.push(v);
			}
		}
	}
	cout << dp["out"][3] << '\n';

	return 0;
}
