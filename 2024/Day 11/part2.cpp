#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long ans = 0;
map<pair<long long, int>, long long> mp;

long long f(long long x, int b) {
	if(b == 75) return 1LL;

	if(x == 0) {
		if(!mp[make_pair(0, b)]) return mp[make_pair(0, b)] = f(1, b+1);
		return mp[make_pair(0, b)];
	}

	string s = to_string(x);
	if(s.size()%2 == 0) {
		long long l = stoll(s.substr(0, s.size()/2)), r = stoll(s.substr(s.size()/2));
		if(!mp[make_pair(x, b)]) mp[make_pair(x, b)] = f(l, b+1) + f(r, b+1);
		return mp[make_pair(x, b)];
	}

	if(!mp[make_pair(x, b)]) mp[make_pair(x, b)] = f(2024*x, b+1);
	return mp[make_pair(x, b)];
}

signed main() {
	freopen("input.txt", "r", stdin);
	
	long long x;
	vector<long long> a;
	while(cin >> x) a.push_back(x);
	
	for(long long i : a) 
		ans += f(i, 0);

	cout << ans << '\n';
}
