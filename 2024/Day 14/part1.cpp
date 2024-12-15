#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

signed main() {
	freopen("input.txt", "r", stdin);

	vector<int> quad(4);
	auto f = [&](int x, int y) {
		if(x==50 || y==51) return;
		if(x<50 && y<51) quad[0]++;
		else if(x<50 && y>51) quad[1]++;
		else if(x>50 && y<51) quad[2]++;
		else quad[3]++;
	};
	string s;
	stringstream ss;
	while(getline(cin, s)) {
		int x, y, vx, vy;

		ss.clear();
		ss.str(s);
		ss.ignore(2);
		ss >> x;
		ss.ignore(1);
		ss >> y;

		ss.ignore(3);
		ss >> vx;
		ss.ignore(1);
		ss >> vy;

		x = ((x + vx*100)%101+101)%101;
		y = ((y + vy*100)%103+103)%103;
		f(x, y);
	}
	
	cout << quad[0]*quad[1]*quad[2]*quad[3] << '\n';
}
