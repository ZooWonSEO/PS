#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
풀이법
0. 기본적인 BFS 문제다.
1. 입력을 잘 받아야 한다. string -> int 변환 주의
2. queue를 활용해서 현재 있는 곳에서 갈 수 있는 곳을 check한다.
3. visited에 현재 온 위치가 몇번째만에 온건지 갱신한다.
*/

int map[101][101];
int visited[101][101];

int x[4] = {0,0,-1,1};
int y[4] = {-1,1,0,0};

void init() {

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j]-'0';
		}
	}

	pair<int, int> p;
	queue<pair<int, int>> q;
	p.first = 0;
	p.second = 0;
	q.push(p);
	visited[0][0] = 1;

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		
		int tmpx = tmp.first;
		int tmpy = tmp.second;

		for (int i = 0; i < 4; i++) {
			int nx = tmpx + x[i];
			int ny = tmpy + y[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			
			if (map[nx][ny] == 0 || visited[nx][ny] != 0)
				continue;

			if (visited[nx][ny]==0 && map[nx][ny] == 1) {
				pair<int, int> np;
				np.first = nx;
				np.second = ny;
				q.push(np);
				visited[nx][ny] = visited[tmpx][tmpy] + 1;
			}
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
}