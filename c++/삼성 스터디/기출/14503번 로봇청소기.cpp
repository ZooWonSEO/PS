#include <iostream>
using namespace std;

int n, m;
int r, c, d;
int map[52][52] = { 0, };
int visited[52][52] = { 0, };

// 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

void dfs(int x, int y, int d) {

	for (int i = 0; i < 4; i++) {

		int nd = (d + 3 - i) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (map[nx][ny] == 1)
			continue;

		if (visited[nx][ny] == 0 && map[nx][ny] == 0) {
			visited[nx][ny] = 1;
			ans++;
			dfs(nx, ny, nd);
		}
	}

	int nx = x + dx[(d + 2) % 4];
	int ny = y + dy[(d + 2) % 4];
	
	if (0 <= nx && nx < n && 0 <= ny && ny < m) {
		if (map[nx][ny] == 0) {
			dfs(nx, ny, d);
		}
		else {
			cout << ans;
			exit(0);
		}
	}

	return;
}

int main() {

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	visited[r][c] = 1;
	ans++;

	dfs(r, c, d);

	return 0;
}