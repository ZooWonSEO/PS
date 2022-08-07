#include <iostream>
using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		int h, w, n;
		cin >> h >> w >> n;

		int floor = n % h;
		if (floor == 0) {
			floor = h;
		}

		int col = 0;
		if (n % h == 0) {
			col = n / h;
		}
		else {
			col = (n / h) + 1;
		}

		cout << floor * 100 + col << '\n';

	}
	
	return 0;
}