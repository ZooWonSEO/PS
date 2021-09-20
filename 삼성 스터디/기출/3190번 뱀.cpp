#include <iostream>
#include <deque>
using namespace std;

int n, k, l;
int map[101][101] = { 0, };
char cmd[10001];
deque<pair<int, int>> q;

// 방향 정보, 우, 상, 좌, 하
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main() {

	cin >> n;
	cin >> k;

	// 사과는 1
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}

	cin >> l;
	
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		cmd[x] = c;
	}

	// 뱀초기정보, 뱀은 -1
	map[0][0] = -1;
	q.push_back(pair<int, int>(0, 0));

	int time = 0;
	int d = 0; // 방향 정보, 초기값은 0으로 오른쪽
	int head_x = 0;
	int head_y = 0;

	while (1) {

		++time;
		
		int nx = head_x + dx[d];
		int ny = head_y + dy[d];

		// 벽에 부딪히는 경우
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			break;
		
		// 자기 자신에게 부딪히는 경우
		if (map[nx][ny] == -1)
			break;
		
		// 그냥 진행
		if (map[nx][ny] == 0) {

			map[q.back().first][q.back().second] = 0;
			map[nx][ny] = -1;
			
			q.pop_back();
			q.push_front(pair<int, int>(nx, ny));
		}

		// 사과일 경우
		else if (map[nx][ny] == 1) {

			map[nx][ny] = -1;
			q.push_front(pair<int, int>(nx, ny));

		}
		
		// 방향 전환
		char ch = ' ';
		ch = cmd[time];

		if (ch == 'L') {

			if (d == 0) {
				d = 1;
			}
			else if (d == 1) {
				d = 2;
			}
			else if (d==2) {
				d = 3;
			}
			else if (d == 3) {
				d = 0;
			}

		}
		else if (ch == 'D') {

			if (d == 0) {
				d = 3;
			}
			else if (d == 1) {
				d = 0;
			}
			else if (d == 2) {
				d = 1;
			}
			else if (d == 3) {
				d = 2;
			}
		}

		head_x = nx;
		head_y = ny;

	}

	cout << time;

	return 0;
}