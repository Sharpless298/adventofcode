#include <iostream>
#include <vector>
#include <map>
using namespace std;

pair<int, int> operator +(pair<int, int> a, pair<int, int> b) {
	return {a.first+b.first, a.second+b.second};
}

vector<pair<int, int>> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
vector<string> G;
map<char, int> dir;

bool check(pair<int, int> cur, int t) {
	pair<int, int> nxt = cur + d[t];

	if(G[nxt.first][nxt.second] == '#') return false;
	else if(G[nxt.first][nxt.second] == '.') return true;
	else if(G[nxt.first][nxt.second] == '[') return check(nxt, t) && check(nxt+d[0], t);
	else return check(nxt, t) && check(nxt+d[2], t);
}

void move(pair<int, int> cur, int t) {
	pair<int, int> nxt = cur + d[t];
	
	if(t==0 || t==2) {
		if(G[nxt.first][nxt.second]=='[' || G[nxt.first][nxt.second]==']') move(nxt, t);
		if(G[nxt.first][nxt.second] == '.') swap(G[cur.first][cur.second], G[nxt.first][nxt.second]);
		return;
	}
	if(t==1 || t==3) {
		if(G[nxt.first][nxt.second] == '[') move(nxt, t), move(nxt+d[0], t);
		if(G[nxt.first][nxt.second] == ']') move(nxt, t), move(nxt+d[2], t);
		swap(G[cur.first][cur.second], G[nxt.first][nxt.second]);
		return;
	}
}

signed main() {
	freopen("input.txt", "r", stdin);

	dir['>'] = 0, dir['^'] = 1, dir['<'] = 2, dir['v'] = 3;

	string s;
	while(getline(cin, s)) {
		if(s.empty()) break;

		string t;
		for(char c : s) {
			if(c == '#') t += "##";
			if(c == 'O') t += "[]";
			if(c == '.') t += "..";
			if(c == '@') t += "@.";
		}
		G.push_back(t);
	}

	string moves;
	while(getline(cin, s)) moves += s;

	int n = (int)G.size(), m = (int)G[0].size();
	pair<int, int> cur;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(G[i][j] == '@') {
				cur = {i, j};
				break;
			}
		}
	}
	
	for(char c : moves) {
		if(c=='>' || c=='<')
			move(cur, dir[c]);
		if((c=='^'  || c=='v') && check(cur, dir[c])) 
			move(cur, dir[c]);
		if(G[cur.first][cur.second] != '@') cur = cur + d[dir[c]];
	}

	int ans = 0;
	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++) 
			if(G[i][j] == '[') ans += 100*i+j;
		
	cout << ans << '\n';
}
