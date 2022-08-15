#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
int check(int left, int right, long long input) {

	while (left <= right) {

		int mid = (left + right) / 2;
		long long cur = v[mid];

		if (cur == input) {
			return 1;
		}
		else if (cur > input) {
			right = mid - 1;
		}
		else if (cur < input) {
			left = mid + 1;
		}
	}

	return 0;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		long long input;
		cin >> input;
		int ans = check(0, n - 1, input);
		cout << ans << '\n';
	}

	return 0;
}