#include <fstream>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

struct DSU {
	vector<int> parent, sz;

	DSU(size_t _n) {
		parent.resize(_n);
		iota(parent.begin(), parent.end(), 0);
		sz.assign(_n, 1);
	}

	int find(int x) {
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}

	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		parent[x] = y;
		sz[y] += sz[x];
		return true;
	}
};

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

	char c;
	int x, y, z;
	vector<tuple<long long, long long, long long>> a;
	while (in >> x >> c >> y >> c >> z) {
		a.push_back({x, y, z});
	}

	auto f = [](tuple<long long, long long, long long> p,
				tuple<long long, long long, long long> q) {
		return (get<0>(p) - get<0>(q)) * (get<0>(p) - get<0>(q)) +
			   (get<1>(p) - get<1>(q)) * (get<1>(p) - get<1>(q)) +
			   (get<2>(p) - get<2>(q)) * (get<2>(p) - get<2>(q));
	};
	priority_queue<tuple<long long, int, int>> pq;
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i + 1; j < (int)a.size(); j++) {
			pq.push(make_tuple(-f(a[i], a[j]), i, j));
		}
	}

	DSU dsu(a.size());
	for (int i = 0; i < 1000; i++) {
		auto [d, u, v] = pq.top();
		pq.pop();
		dsu.unite(u, v);
	}
	sort(dsu.sz.begin(), dsu.sz.end(), greater<int>());
	long long ans = 1;
	for (int i = 0; i < 3; i++) {
		ans *= dsu.sz[i];
	}
	cout << ans << '\n';

	return 0;
}
