#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int t[16] = { 0, };
int p[16] = { 0, };

int mx = -1;

void dfs(int cur_day, int cur_money, int add_money) {

	if (cur_day == n + 1) {
		mx = max(mx, cur_money);
		return;
	}

	if (cur_day > n + 1) {
		mx = max(mx, cur_money - add_money);
		return;
	}

	int next_day = cur_day + t[cur_day];
	cur_money = cur_money + p[cur_day];
	add_money = p[cur_day];

	for (int i = next_day; i <= next_day+t[next_day]; i++) {
		dfs(i, cur_money, add_money);
	}

	return;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, 0, 0);
	}

	cout << mx;

	return 0;
}