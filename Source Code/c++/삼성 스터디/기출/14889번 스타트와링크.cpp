#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
풀이법
0. 조합, 백트래킹을 사용해 풀었다.
1. 주의해야할 점은 두 능력치의 차를 구할 때, 절댓값을 씌우는 부분이다.
*/

int n;
int map[21][21];
int visited[21] = { 0, };
int mn = 999999999;
vector<int> v;

void dfs(int start, int cnt) {

	if (cnt == (n / 2)) {

		vector<int> t1;
		vector<int> t2;
		int s1 = 0;
		int s2 = 0;

		for (int i = 0; i < n; i++) {
			if (visited[i] == 1) {
				t1.push_back(i);
			}
			else {
				t2.push_back(i);
			}
		}

		for (int i = 0; i < t1.size(); i++) {
			for (int j = 0; j < t1.size(); j++) {
				s1 = s1 + map[t1[i]][t1[j]];
				s2 = s2 + map[t2[i]][t2[j]];
			}
		}

		mn = min(mn, abs(s1 - s2));

		return;
	}

	for (int i = start; i < n; i++) {

		if (visited[i] == 1)
			continue;
		
		visited[i] = 1;
		v.push_back(i);
		dfs(i, cnt + 1);
		v.pop_back();
		visited[i] = 0;
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

	dfs(0, 0);

	cout << mn;

	return 0;
}