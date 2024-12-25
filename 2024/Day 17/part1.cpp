#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	string s;
	getline(cin, s);
	int A = stoi(s.substr(12));
	getline(cin, s);
	int B = stoi(s.substr(12));
	getline(cin, s);
	int C = stoi(s.substr(12));

	cin.ignore();
	getline(cin, s);
	stringstream ss(s);
	ss.ignore(8);
	int x;
	vector<int> a;
	while(ss >> x) {
		ss.ignore(1);
		a.push_back(x);
	}
	
	string ans;
	for(int i=0; i<(int)a.size(); ) {
		int combo;
		switch(a[i+1]) {
			case 0 ... 3:
				combo = a[i+1];
				break;
			case 4:
				combo = A;
				break;
			case 5:
				combo = B;
				break;
			case 6:
				combo = C;
				break;
			default: 
				break;
		}
		switch(a[i]) {
			case 0:
				A >>= combo;
				break;
			case 1:
				B ^= a[i+1];
				break;
			case 2:
				B = combo % 8;
				break;
			case 3:
				if(A == 0) break;
				i = a[i+1];
				continue;
			case 4:
				B ^= C;
				break;
			case 5:
				ans += to_string(combo%8)+',';
				break;
			case 6:
				B = A>>combo;
				break;
			case 7:
				C = A>>combo;
				break;
		}
		i += 2;
	}
	
	ans.pop_back();
	cout << ans << '\n';
}
