#include <iostream>
using namespace std;

const long long MOD = 16777216;

long long mix(long long a, long long b) {
	return a^b;
}

long long prune(long long a) {
	return a % MOD;
}

signed main() {
	freopen("input.txt", "r", stdin);

	int T = 10;
	long long t = 123LL;
	while(T--) {
		t = prune(mix(t*64, t));
		t = prune(mix((t/32), t));
		t = prune(mix(t*2048, t));
		cout << t << '\n';
	}
}
