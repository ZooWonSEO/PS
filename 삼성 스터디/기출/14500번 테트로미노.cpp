#include <iostream>
#include <algorithm>
using namespace std;

/*
풀이법
0. 'ㅜ' 모양 빼고는 다른 도형은 백트래킹과 dfs를 활용해 대칭까지 구할 수 있다.
*/

int n, m;
int map[501][501];
int visited[501][501] = { 0, };
int mx = -1;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

void dfs(int x, int y, int cnt, int total) {

	if (cnt == 4) {
		mx = max(mx, total);
		return;
	}

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny<0 || nx >= n || ny >= m)
			continue;

		if (visited[nx][ny] == 1)
			continue;

		visited[nx][ny] = 1;
		dfs(nx, ny, cnt + 1, total + map[nx][ny]);
		visited[nx][ny] = 0;
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	int tmp = 0;

	// ㅜ 도형
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			mx = max(mx, tmp);
		}
	}
	
	// ㅗ 도형
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m - 2; j++) {
			tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
			mx = max(mx, tmp);
		}
	}

	// ㅓ, ㅏ 도형
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			tmp = map[i][j] + map[i - 1][j + 1] + map[i][j + 1] + map[i + 1][j + 1];
			mx = max(mx, tmp);
			tmp = map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j + 1];
			mx = max(mx, tmp);
		}
	}

	// 나머지 도형들
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			visited[i][j] = 0;
		}
	}

	cout << mx;

	return 0;
}