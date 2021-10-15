#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[9][9] = { 0, };
int tmp_map[9][9] = { 0, };

vector<pair<int, int>> cctv;
vector<int> dir;

int answer = 999999;

void init() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
	return;
}

void up(int x, int y) {
	for (int i = x-1; i >=0; i--) {
		if (tmp_map[i][y] == 6)
			break;

		if (tmp_map[i][y] == 0) {
			tmp_map[i][y] = -1;
		}
	}
	return;
}

void down(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (tmp_map[i][y] == 6)
			break;

		if (tmp_map[i][y] == 0) {
			tmp_map[i][y] = -1;
		}
	}
	return;
}

void left(int x, int y) {
	for (int i = y - 1; i >=0; i--) {
		if (tmp_map[x][i] ==6)
			break;

		if (tmp_map[x][i] == 0) {
			tmp_map[x][i] = -1;
		}
	}
	return;
}

void right(int x, int y) {
	for (int i = y + 1; i < m; i++) {
		if (tmp_map[x][i] ==6)
			break;

		if (tmp_map[x][i] == 0) {
			tmp_map[x][i] = -1;
		}
	}
	return;
}

void watch() {

	for (int i = 0; i < dir.size(); i++) {
		
		int x = cctv[i].first;
		int y = cctv[i].second;
		int type = tmp_map[x][y];
		int d = dir[i];

		// 우, 상, 좌, 하

		if (type == 1) {
			if (d == 0) {
				right(x, y);
			}
			else if (d == 1) {
				up(x, y);
			}
			else if (d == 2) {
				left(x, y);
			}
			else if (d == 3) {
				down(x, y);
			}
		}
		
		else if (type == 2) {
			if (d == 0) {
				left(x, y);
				right(x, y);
			}
			else if (d == 1) {
				up(x, y);
				down(x, y);
			}
		}

		else if (type == 3) {
			if (d == 0) {
				up(x, y);
				right(x, y);
			}
			else if (d == 1) {
				right(x, y);
				down(x, y);
			}
			else if (d == 2) {
				down(x, y);
				left(x, y);
			}
			else if (d == 3) {
				left(x, y);
				up(x, y);
			}
		}

		else if (type == 4) {
			if (d == 0) {
				left(x, y);
				up(x, y);
				right(x, y);
			}
			else if (d == 1) {
				up(x, y);
				right(x, y);
				down(x, y);
			}
			else if (d == 2) {
				right(x, y);
				down(x, y);
				left(x, y);
			}
			else if (d == 3) {
				down(x, y);
				left(x, y);
				up(x, y);
			}
		}

		else if (type == 5) {
			right(x, y);
			down(x, y);
			left(x, y);
			up(x,y);
		}
	}

	return;
}

void check() {

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_map[i][j] == 0) {
				cnt++;
			}
		}
	}

	answer = min(answer, cnt);
	return;
}

void dfs(int cnt) {

	if (cnt == cctv.size()) {

		init();
		watch();
		check();
		return;
	}

	for (int i = 0; i < 4; i++) {

		if (map[cctv[cnt].first][cctv[cnt].second] == 2) {
			dir.push_back(i % 2);
		}
		else if (map[cctv[cnt].first][cctv[cnt].second] == 5) {
			dir.push_back(0);
		}
		else {
			dir.push_back(i);
		}
		dfs(cnt + 1);
		dir.pop_back();
	}

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if (map[i][j] >=1 && map[i][j]<=5) {
				cctv.push_back(pair<int, int>(i,j));
			}
		}
	}

	dfs(0);

	cout << answer;

	return 0;
}