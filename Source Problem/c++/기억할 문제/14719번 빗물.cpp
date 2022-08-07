#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int h, w;
	cin >> h >> w;

	int arr[502] = { 0 };

	for (int i = 1; i <=w; i++) {
		cin >> arr[i];
	}

	int le[502] = { 0, };
	int re[502] = { 0, };

	for (int i = 1; i <= w; i++) {
		le[i] = max(le[i - 1], arr[i]);
	}

	for (int i = w; i > 0; i--) {
		re[i] = max(re[i + 1], arr[i]);
	}

	int dp[502] = { 0, };
	for (int i = 1; i <= w; i++) {
		dp[i] =  min(le[i], re[i]);
	}

	int ans = 0;
	for (int i = 1; i <= w; i++) {
		ans = ans + (dp[i] - arr[i]);
	}

	cout << ans;

	return 0;
}