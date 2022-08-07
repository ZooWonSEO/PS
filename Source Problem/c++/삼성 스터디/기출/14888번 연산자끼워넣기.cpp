#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
풀이법
0. 재귀를 사용하면 된다.
*/


int n;
int a[101] = { 0, };
int m_plus, m_minus, m_multi, m_div;
int total = 0;
int mx = -1000000001;
int mn = 1000000001;

void dfs(int m_plus, int m_minus, int m_multi, int m_div, int total, int cnt) {

	if (cnt==n) {
		mx = max(mx, total);
		mn = min(mn, total);
		return;
	}

	if (m_plus > 0) {
		dfs(m_plus - 1, m_minus, m_multi, m_div, total + a[cnt], cnt + 1);
	}

	if (m_minus > 0) {
		dfs(m_plus, m_minus - 1, m_multi, m_div, total - a[cnt], cnt+1);
	}

	if (m_multi > 0) {
		dfs(m_plus, m_minus, m_multi - 1, m_div, total * a[cnt], cnt + 1);
	}

	if (m_div > 0) {
		dfs(m_plus, m_minus, m_multi, m_div - 1, total / a[cnt], cnt + 1);
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m_plus >> m_minus >> m_multi >> m_div;

	total = a[0];
	dfs(m_plus, m_minus, m_multi, m_div, total,1);


	cout << mx << '\n';
	cout << mn;

	return 0;
}