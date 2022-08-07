#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[1001];
	double m = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > m) {
			m = arr[i];
		}
	}

	double avg = 0;
	for (int i = 0; i < n; i++) {
		avg = avg + (arr[i] / m ) * 100;
	}

	cout.precision(6);
	cout << fixed;
	cout << avg / n;

	return 0;
}