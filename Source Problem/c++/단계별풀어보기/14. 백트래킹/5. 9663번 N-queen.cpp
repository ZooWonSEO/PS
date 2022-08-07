#include <iostream>
using namespace std;

int n;
int visited[15] = { 0, };
int ans = 0;

int check(int cnt) {

	for (int i = 0; i < cnt; i++) {

		// cnt와 같은 행에 있는 퀸은 배제
		if (visited[cnt] == visited[i]) {
			return 0;
		}

		// cnt의 대각에 있는 퀸은 배제
		if (cnt - i == abs(visited[cnt] - visited[i])) {
			return 0;
		}
	}

	return 1;
}

void dfs(int cnt) {

	if (cnt == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		visited[cnt] = i;
		if (check(cnt) == 1) {
			dfs(cnt + 1);
		}
	}
	return;
}

int main() {

	cin >> n;
	dfs(0);
	cout << ans;

	return 0;
}