#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
풀이법
주의점 : 꼭 arr를 복사하자. 원본이 바뀐다.
*/

int n;
int map[21][21] = { 0, };
int mx = -1;

void dfs(int arr[21][21], int cnt, int dir) {

	int tmp[21][21];
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	if (cnt == 5) {

		//cout << "---------------" << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//cout << tmp[i][j] << " ";
				mx = max(mx, tmp[i][j]);
			}
			//cout << '\n';
		}
		//cout << "---------------" << '\n';
		return;
	}
;
	// 위
	if (dir == 0) {

		// 열
		for (int j = 0; j < n; j++) {
			queue<int> q;
			vector<int> v;

			// 행
			for (int i = 0; i < n; i++) {
				if (tmp[i][j] != 0) {
					q.push(tmp[i][j]);
				}
				tmp[i][j] = 0;
			}

			while (!q.empty()) {

				int cur = q.front(); // 2
				q.pop();
				
				if (q.empty()) {
					v.push_back(cur);
					break;
				}

				int next = q.front(); // 4
				if (cur == next) {
					v.push_back(cur * 2);
					q.pop();
				}
				else {
					v.push_back(cur);
				}
			}

			for (int i = 0; i < v.size(); i++) {
				tmp[i][j] = v[i];
			}
		}
	}
	// 오른
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			queue<int> q;
			vector<int> v;

			for (int j = n-1; j >= 0; j--) {
				if (tmp[i][j] != 0) {
					q.push(tmp[i][j]);
				}
				tmp[i][j] = 0;
			}

			while (!q.empty()) {

				int cur = q.front();
				q.pop();

				if (q.empty()) {
					v.push_back(cur);
					break;
				}

				int next = q.front();
				if (cur == next) {
					v.push_back(cur * 2);
					q.pop();
				}
				else {
					v.push_back(cur);
				}
			}

			for (int j = 0; j < v.size(); j++) {
				tmp[i][j] = v[j];
			}
		}
	}
	// 아래
	else if (dir == 2) {
		for (int j = 0; j < n; j++) {
			queue<int> q;
			vector<int> v;

			for (int i = n-1; i >= 0; i--) {
				if (tmp[i][j] != 0) {
					q.push(tmp[i][j]);
				}
				tmp[i][j] = 0;
			}

			while (!q.empty()) {

				int cur = q.front();
				q.pop();

				if (q.empty()) {
					v.push_back(cur);
					break;
				}

				int next = q.front();
				if (cur == next) {
					v.push_back(cur * 2);
					q.pop();
				}
				else {
					v.push_back(cur);
				}
			}

			for (int i = 0; i < v.size(); i++) {
				tmp[i][j] = v[i];
			}
		}
	}
	// 왼
	else if (dir == 3) {
		for (int i = 0; i < n; i++) {
			queue<int> q;
			vector<int> v;

			for (int j = 0; j < n; j++) {
				if (tmp[i][j] != 0) {
					q.push(tmp[i][j]);
				}
				tmp[i][j] = 0;
			}

			while (!q.empty()) {

				int cur = q.front();
				q.pop();

				if (q.empty()) {
					v.push_back(cur);
					break;
				}

				int next = q.front();
				if (cur == next) {
					v.push_back(cur * 2);
					q.pop();
				}
				else {
					v.push_back(cur);
				}
			}

			for (int j = 0; j < v.size(); j++) {
				tmp[i][j] = v[j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		dfs(tmp, cnt + 1, i);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	// 위, 오른, 아래, 왼
	for (int i = 0; i < 4; i++) {
		dfs(map, 0, i);
	}

	cout << mx;

	return 0;
}