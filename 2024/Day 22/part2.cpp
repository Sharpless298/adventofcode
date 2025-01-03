#include <iostream>
#include <vector>
#include <map>
#include <set>
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

	long long t;
	map<vector<int>, int> mp;
	while(cin >> t) {
		vector<int> v;
		v.push_back((int)(t%10));

		set<vector<int>> s;
		for(int i=0; i<2000; i++) {
			f(t);
			v.push_back((int)(t%10));
			if(i >= 3) {
				vector<int> d;
				for(int j=0; j<4; j++) 
					d.push_back(v[i-4+1+j+1]-v[i-4+j+1]);
				if(!s.count(d)) {
					s.insert(d);
					mp[d] += (int)(t%10);
				}
			}
		}
	}
	
	int ans = 0;
	for(auto i : mp)
		ans = max(ans, i.second);
	cout << ans << '\n';
}
