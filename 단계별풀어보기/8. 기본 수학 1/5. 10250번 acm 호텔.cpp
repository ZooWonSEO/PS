#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while (t--) {

		int h, w, n;
		cin >> h >> w >> n;

		int a = (n-1) / h + 1;
		int b = n % h;

		if (b == 0) {
			b = h;
		}

		cout << b * 100 + a << '\n';

	}
	
	return 0;
}