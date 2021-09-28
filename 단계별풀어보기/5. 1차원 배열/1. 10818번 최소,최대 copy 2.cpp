#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int mx = -1000002;
	int mn = 1000002;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (input > mx) {
			mx = input;
		}
		if (input <= mn) {
			mn = input;
		}
	}
	
	cout << mn << " " << mx;

	return 0;
}