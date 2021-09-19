#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
풀이법
0. BFS를 사용해서 풀었다.
*/

int n, m;
char map[10][10];
int visited[10][10][10][10] = { 0, };

struct info {
	int rx, ry, bx, by, cnt;
};

info start;
queue<info> q;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int ans = -1;

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		
		string tmp;
		cin >> tmp;

		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[j];

			if (map[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}

			if (map[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}

	start.cnt = 0;
	q.push(start);

	while (!q.empty()) {
		
		info cur = q.front();
		q.pop();
		visited[cur.rx][cur.ry][cur.bx][cur.by] = 1;

		if (cur.cnt > 10)
			break;
		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			ans = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {

			int nrx = cur.rx;
			int nry = cur.ry;
			int nbx = cur.bx;
			int nby = cur.by;

			while (1) {
				
				if (map[nrx][nry] != '#' && map[nrx][nry] != 'O') {
					nrx = nrx + dx[i];
					nry = nry + dy[i];
				}
				else {
					// 벽이거나 구멍일 경우
					if (map[nrx][nry] == '#') {
						nrx = nrx - dx[i];
						nry = nry - dy[i];
					}
					break;
				}
			}

			while (1) {

				if (map[nbx][nby] != '#' && map[nbx][nby] != 'O') {
					nbx = nbx + dx[i];
					nby = nby + dy[i];
				}
				else {
					// 벽이거나 구멍일 경우
					if (map[nbx][nby] == '#') {
						nbx = nbx - dx[i];
						nby = nby - dy[i];
					}
					break;
				}
			}

			if (nrx == nbx && nry == nby) {
				if (map[nrx][nry] != 'O') {
					int rdist = abs(nrx - cur.rx) + abs(nry - cur.ry);
					int bdist = abs(nbx - cur.bx) + abs(nby - cur.by);

					if (rdist > bdist) {
						nrx = nrx - dx[i];
						nry = nry - dy[i];
					}
					else {
						nbx = nbx - dx[i];
						nby = nby - dy[i];
					}
				}
			}

			if (visited[nrx][nry][nbx][nby] == 0) {
				info next;
				next.rx = nrx;
				next.ry = nry;
				next.bx = nbx;
				next.by = nby;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}
	}

	cout << ans;

	return 0;
}