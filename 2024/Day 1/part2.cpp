#include <iostream>
#include <vector>
#include <map>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);
	
	int x, y;
	vector<int> a;
	map<int, int> mp;
	while(cin >> x >> y) { 
		a.push_back(x), mp[y]++;
	}

	int sum = 0;
	for(int i=0; i<(int)a.size(); i++) 
		sum += abs(a[i]*mp[a[i]]);
	
	cout << sum << '\n';
}
