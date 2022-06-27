#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int op[4] = { 0, };

int mx = -1000000001;
int mn = 1000000001;

void dfs(int plus, int minu, int multi, int div, int cnt, int total) {

	if (cnt == v.size()) {
		
		mx = max(mx, total);
		mn = min(mn, total);
		return;
	}

	if (plus > 0) {
		dfs(plus - 1, minu, multi, div, cnt + 1, total + v[cnt]);
	}

	if (minu > 0) {
		dfs(plus, minu - 1, multi, div, cnt + 1, total - v[cnt]);
	}

	if (multi > 0) {
		dfs(plus, minu, multi - 1, div, cnt + 1, total * v[cnt]);
	}

	if (div > 0) {
		dfs(plus, minu, multi, div - 1, cnt + 1, total /  v[cnt]);
	}

	return;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(op[0], op[1], op[2], op[3], 1, v[0]);

	cout << mx << '\n' << mn;

	return 0;
}