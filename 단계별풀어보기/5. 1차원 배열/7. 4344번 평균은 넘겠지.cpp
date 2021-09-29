#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {

		int n;
		cin >> n;

		int arr[1001];
		double avg = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			avg = avg + arr[j];
		}

		avg = avg / n;
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (arr[j] > avg) {
				cnt++;
			}
		}

		cout.precision(3);
		cout << fixed;
		cout << (double)cnt / n * 100 << '%' << '\n';
	}

	return 0;
}