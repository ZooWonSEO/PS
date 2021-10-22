#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1002] = { 0, };
int le[1002] = { 0, };
int re[1002] = { 0, };

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	le[0] = 0;
	re[1001] = 0;

	for (int i = 1; i <= 1000; i++) {
		le[i] = max(le[i - 1], arr[i]);
	}

	for (int i = 1000; i > 0; i--) {
		re[i] = max(re[i + 1], arr[i]);
	}

	int ans = 0;

	for (int i = 1; i <= 1000; i++) {
		ans = ans + min(le[i], re[i]);
	}

	cout << ans;

	return 0;
}