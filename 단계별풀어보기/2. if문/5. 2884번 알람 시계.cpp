#include <iostream>
using namespace std;

int main() {
	
	int h, m;
	cin >> h >> m;

	int res_h, res_m = 0;

	if (m - 45 < 0) {
		res_m = m + 15;
		if (h - 1 < 0) {
			res_h = 23;
		}
		else {
			res_h = h - 1;
		}
	}
	else {
		res_m = m - 45;
		res_h = h;
	}

	cout << res_h << " " << res_m;

	return 0;
}