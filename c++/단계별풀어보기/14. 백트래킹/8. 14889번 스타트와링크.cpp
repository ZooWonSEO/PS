#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> t1;
int map[21][21] = { 0, };
int visited[21] = { 0, };
int mn = 999999999;

void dfs(int target, int cnt, int start) {

	if (target == cnt) {

		vector<int> t2;

		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				t2.push_back(i);
			}
		}

		int s1 = 0;
		int s2 = 0;

		for (int i = 0; i < (n/2) - 1; i++) {
			for (int j = i+1; j < n/2; j++) {
				s1 = s1 + map[t1[i]][t1[j]] + map[t1[j]][t1[i]];
				s2 = s2 + map[t2[i]][t2[j]] + map[t2[j]][t2[i]];
			}
		}
		
		mn = min(mn, abs(s1 - s2));

		return;
	}

	for (int i = start; i < n; i++) {

		if (visited[i] == 1)
			continue;
		
		visited[i] = 1;
		t1.push_back(i);
		dfs(target, cnt + 1, i);
		t1.pop_back();
		visited[i] = 0;
	}

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	dfs(n / 2, 0, 0);
	
	cout << mn;

	return 0;
}