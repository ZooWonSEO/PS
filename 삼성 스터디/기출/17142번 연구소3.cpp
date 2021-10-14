#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[52][52] = { 0, };

vector<pair<int, int>> virus;
int virus_visited[12] = { 0, };
vector<int> active;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1 ,1};

int tmp_map[52][52] = { 0, };
int visited[52][52] = { -1, };

int emp = 0;
int cnt = 0;

int answer = 999999999;

void init() {

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			tmp_map[i][j] = 0;
			visited[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}

	return;
}

void bfs() {

	init();

	int mx = 0;
	cnt = 0;

	queue<pair<int, int>> q;

	for (int i = 0; i < active.size(); i++) {
		q.push(virus[active[i]]);
		visited[virus[active[i]].first][virus[active[i]].second] = 0;
	}

	while (!q.empty()) {

		pair<int, int> p = q.front();
		q.pop();

		int x = p.first;
		int y = p.second;

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >=n )
				continue;

			if (tmp_map[nx][ny] != 1 && visited[nx][ny] == -1) {
				
				visited[nx][ny] = visited[x][y] + 1;
				if (tmp_map[nx][ny] == 0) {
					cnt++;
					mx = max(mx, visited[nx][ny]);
				}
				q.push(pair<int, int>(nx,ny));
			}

		}
	}
	
	if (cnt == emp) {
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

		if (virus_visited[i] == 1)
			continue;

		virus_visited[i] = 1;
		active.push_back(i);
		dfs(i, cnt + 1);
		active.pop_back();
		virus_visited[i] = 0;
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

	if (answer == 999999999) {
		answer = -1;
	}

	cout << answer;

	return 0;
}