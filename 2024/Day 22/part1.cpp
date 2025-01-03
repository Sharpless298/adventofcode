#include <iostream>
using namespace std;

const int MOD = 1<<24;

void f(long long &x) {
	x ^= x*64;
	x %= MOD;
	x ^= x/32;
	x %= MOD;
	x ^= x*2048LL;
	x%= MOD;
}

signed main() {
	freopen("input.txt", "r", stdin);

	long long t, ans = 0;
	while(cin >> t) {
		for(int i=0; i<2000; i++) 
			f(t);
		ans += t;
	}
	cout << ans << '\n';
}
