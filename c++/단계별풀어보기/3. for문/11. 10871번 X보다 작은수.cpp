#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n >> x;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		if (number < x) {
			cout << number << " ";
		}
	}

	return 0;
}