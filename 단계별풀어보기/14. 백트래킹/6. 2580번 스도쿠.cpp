#include <iostream>
#include <vector>
using namespace std;

int map[9][9] = { 0, };
vector<pair<int, int>> v;
int zero_cnt = 0;

bool check(int x, int y, int num) {

	// 열 검사
	for (int i = 0; i < 9; i++) {
		if (num == map[x][i]) {
			return false;
		}
	}

	// 행 검사
	for (int i = 0; i < 9; i++) {
		if (num == map[i][y]) {
			return false;
		}
	}

	// 3*3 검사
	x = x / 3;
	y = y / 3;
	for (int i = x * 3; i < x * 3 + 3; i++) {
		for (int j = y * 3; j < y * 3 + 3; j++) {
			if (map[i][j] == num) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int idx) {

	if (idx == zero_cnt) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++) {
		
		int x = v[idx].first;
		int y = v[idx].second;
		
		if (check(x, y, i) == true) {
			map[x][y] = i;
			dfs(idx + 1);
			map[x][y] = 0;
		}
	}

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) {
				zero_cnt++;
				v.push_back(pair<int, int>(i,j));
			}
		}
	}

	dfs(0);

	return 0;
}