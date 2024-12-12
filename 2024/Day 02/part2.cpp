#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	int ans = 0;
	string s;
	while(getline(cin, s)) {
		stringstream ss(s);

		vector<int> a;
		for(int x; ss>>x; a.push_back(x));
		
		bool ok = true;
		for(int i=0; i<(int)a.size()-1; i++) {
			int d = a[i]-a[i+1];
			if(d>=0 || d<-3) {
				ok = false;
				break;
			}
		}
		if(ok) {ans++; continue;}

		ok = true;
		for(int i=0; i<(int)a.size()-1; i++) {
			int d = a[i]-a[i+1];
			if(d<=0 || d>3) {
				ok = false;
				break;
			}
		}
		if(ok) {ans++; continue;}
		
		for(int i=0; i<(int)a.size(); i++) {
			ok = true;
			for(int j=0; j<(int)a.size()-1; j++) {
				if(j == i) continue;
				
				int nxt = j+1;
				if(nxt == i) nxt++;
				if(nxt == (int)a.size()) continue;

				int d = a[j]-a[nxt];
				if(d>=0 || d<-3) {
					ok = false;
					break;
				}
			}
			if(ok) break;
		}
		if(ok) {ans++; continue;}

		for(int i=0; i<(int)a.size(); i++) {
			ok = true;
			for(int j=0; j<(int)a.size()-1; j++) {
				if(j == i) continue;
				
				int nxt = j+1;
				if(nxt == i) nxt++;
				if(nxt == (int)a.size()) continue;

				int d = a[j]-a[nxt];
				if(d<=0 || d>3) {
					ok = false;
					break;
				}
			}
			if(ok) break;
		}
		if(ok) ans++;
	}

	cout << ans << '\n';
}
