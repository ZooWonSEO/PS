#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int mx = -1000002;
	int idx = -1;

	for (int i = 0; i < 9; i++) {
		int input;
		cin >> input;

		if (input > mx) {
			mx = input;
			idx = i+1;
		}
	}
	
	cout << mx << "\n" << idx;

	return 0;
}