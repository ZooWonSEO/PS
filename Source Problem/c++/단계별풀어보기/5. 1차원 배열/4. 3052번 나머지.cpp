#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[42] = { 0, };

	for (int i = 0; i < 10; i++) {
		int input;
		cin >> input;
		arr[input % 42] ++;
	}

	int cnt = 0;

	for (int i = 0; i < 42; i++) {
		if (arr[i] > 0) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}