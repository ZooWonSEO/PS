#include <iostream>
using namespace std;

int main() {

	int n;

	while (cin >> n) {
		
		if (n == 1) {
			cout << 1 << '\n';
		}

		else {

			int ans = 1;
			int tmp = 1;

			while (1) {

				if (tmp % n == 0) {
					cout << ans << '\n';
					break;
				}

				tmp = (tmp * 10 + 1) % n;
				ans++;

			}
		}

	}

	return 0;
}