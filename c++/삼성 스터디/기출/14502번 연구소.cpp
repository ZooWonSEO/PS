#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
풀이법
0. 백트래킹 조합으로 벽이 들어가는 경우를 구했다.
1. 벽이 3개 구해지면 그 map을 가지고 bfs를 실행한다.
*/

int n, m;
int map[8][8];
int tmp[8][8];
int visited[8][8] = { 0, };
int check_nw[8][8] = { 0, };

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

vector<pair<int, int>> virus;
vector<pair<int, int>> nw;
queue<pair<int, int>> q;

int ans = -1;

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			tmp[i][j] = map[i][j];
		}
	}
}

void clear_q() {

	while (!q.empty()) {
		q.pop();
	}
}

void bfs() {

	clear();

	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}

	while (!q.empty()) {

		int cur_x = q.front().first;
		int cur_y = q.front().second;

		q.pop();
		visited[cur_x][cur_y] = 1;

		for (int i = 0; i < 4; i++) {

			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			// 구역을 벗어나면 패스
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			// 이미 방문 했다면 패스
			if (visited[nx][ny] == 1)
				continue;

			// 벽이거나 바이러스면 패스
			if (tmp[nx][ny] == 1 || tmp[nx][ny] == 2)
				continue;

			tmp[nx][ny] = 2;
			q.push(pair<int, int>(nx, ny));
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}

	ans = max(ans, cnt);
	
}

void dfs(int start, int cnt) {

	if (cnt == 3) {
		clear_q();
		bfs();
		return;
	}

	for (int i = start; i < nw.size(); i++) {

		if (map[nw[i].first][nw[i].second] == 1)
			continue;
		
		map[nw[i].first][nw[i].second] = 1;
		dfs(i, cnt + 1);
		map[nw[i].first][nw[i].second] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				virus.push_back(pair<int, int>(i, j));
			}

			if (map[i][j] == 0) {
				nw.push_back(pair<int, int>(i, j));
			}

		}
	}

	dfs(0, 0);

	cout << ans;

	return 0;
}