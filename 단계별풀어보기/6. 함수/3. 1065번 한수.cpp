#include <iostream>
using namespace std;

int arr[1001] = { 0, };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= 99; i++) {
		arr[i] = 1;
	}

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 4; j++) {
			int ten = i + j;
			int one = ten + j;

			if (ten >= 10 || one >= 10)
				continue;

			int num = i * 100 + ten * 10 + one;
			int num2 = one * 100 + ten * 10 + i;

			if (num > 100) {
				arr[num] = 1;
			}
			if (num2 > 100) {
				arr[num2] = 1;
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}