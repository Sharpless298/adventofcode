#include <fstream>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
	long long d;
	int u, v;

	bool operator<(const Edge &rhs) const {
		return d < rhs.d;
	};
};

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

inline long long f(const tuple<long long, long long, long long> &p,
				   const tuple<long long, long long, long long> &q) {
	return (get<0>(p) - get<0>(q)) * (get<0>(p) - get<0>(q)) +
		   (get<1>(p) - get<1>(q)) * (get<1>(p) - get<1>(q)) +
		   (get<2>(p) - get<2>(q)) * (get<2>(p) - get<2>(q));
}

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

	vector<Edge> edges;
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = i + 1; j < (int)a.size(); j++) {
			edges.push_back((Edge){-f(a[i], a[j]), i, j});
		}
	}

	priority_queue<Edge> pq(edges.begin(), edges.end());
	DSU dsu(a.size());
	long long ans = -1;
	while (!pq.empty()) {
		auto &[d, u, v] = pq.top();
		pq.pop();
		if (dsu.unite(u, v)) {
			ans = get<0>(a[u]) * get<0>(a[v]);
		}
	}
	cout << ans << '\n';

	return 0;
}
