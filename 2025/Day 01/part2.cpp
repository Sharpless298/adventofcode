#include <fstream>
#include <iostream>
using namespace std;

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
	int x, cur = 50, ans = 0;
	while (in >> c >> x) {
		ans += x / 100;
		x = (x % 100) * (c == 'L' ? -1 : 1);
		ans += ((cur != 0 && cur + x <= 0) || cur + x >= 100);
		cur = ((cur + x) % 100 + 100) % 100;
	}
	cout << ans << '\n';

	return 0;
}
