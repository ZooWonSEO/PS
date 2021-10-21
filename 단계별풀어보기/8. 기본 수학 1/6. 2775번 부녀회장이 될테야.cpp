#include <iostream>
using namespace std;

int main() {

	int t;
	cin >> t;

	int arr[16][16] = { 0, };

	for (int i = 0; i < 16; i++) {
		arr[0][i] = i + 1;
	}

	for (int i = 1; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (j == 0) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
	}

	while (t--) {

		int k, n;
		cin >> k >> n;
		cout << arr[k][n-1] << '\n';
	}
	
	return 0;
}