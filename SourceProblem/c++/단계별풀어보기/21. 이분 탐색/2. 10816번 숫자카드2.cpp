#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		
		auto left = lower_bound(v.begin(), v.end(), input);
		auto right = upper_bound(v.begin(), v.end(), input);

		cout << right - left << " ";
	}

	return 0;
}