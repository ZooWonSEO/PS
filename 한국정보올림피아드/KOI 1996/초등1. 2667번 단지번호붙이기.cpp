#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int map[26][26] = { 0, };
int visited[26][26] = { 0, };

int total = 0;
int cnt = 0;
vector<int> v;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {

	cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny<0 || nx >= n || ny >= n)
			continue;

		if (visited[nx][ny] == 1 || map[nx][ny] == 0)
			continue;

		if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 1 || map[i][j]==0)
				continue;
			
			if (map[i][j] == 1 && visited[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				total++;
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << total << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	
	return 0;
}