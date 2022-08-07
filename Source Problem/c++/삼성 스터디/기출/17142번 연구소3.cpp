#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[52][52] = { 0, };

vector<pair<int, int>> virus;
vector<int> v;
int v_visited[11] = { 0, };

int tmp_map[52][52] = { 0, };
int visited[52][52] = { 0, };

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int emp = 0;
int answer = 999999;

void init() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
			visited[i][j] = -1;
		}
	}

	return;
}

void bfs() {

	int cnt = 0;
	int mx = 0;

	init();

	queue<pair<int, int>> q;

	for (int i = 0; i < v.size(); i++) {
		pair<int, int> p = virus[v[i]];
		q.push(p);
		visited[p.first][p.second] = 0;
	}

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (visited[nx][ny] == -1 && tmp_map[nx][ny] != 1) {

				visited[nx][ny] = visited[x][y] + 1;

				if (tmp_map[nx][ny] == 0) {
					cnt++;
					mx = max(mx, visited[nx][ny]);
				}

				q.push(pair<int, int>(nx,ny));
			}
		}
	}

	if (emp == cnt) {
		answer = min(answer, mx);
	}

	return;
}

void dfs(int start, int cnt) {

	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = start; i < virus.size(); i++) {

		if (v_visited[i] == 1)
			continue;

		v_visited[i] = 1;
		v.push_back(i);
		dfs(i, cnt + 1);
		v.pop_back();
		v_visited[i] = 0;
	}
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				virus.push_back(pair<int, int>(i,j));
			}

			if (map[i][j] == 0) {
				emp++;
			}
		}
	}

	dfs(0, 0);

	if (answer == 999999) {
		answer = -1;
	}
	cout << answer;

	return 0;
}