#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[52][52] = { 0, };
int tmp_map[52][52] = { 0, };

vector<pair<int, int>> home;
vector<pair<int, int>> bbq;
int bbq_cnt = 0;

vector<int> v;
int visited[13] = { 0, };

int answer = 999999999;

void init(){

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		pair<int, int> p = bbq[v[i]];
		tmp_map[p.first][p.second] = 0;
	}
	return;
}

void distance() {

	int total = 0;

	for (int i = 0; i < home.size(); i++) {
		
		int tmp = 99999999;

		for (int j = 0; j < bbq.size(); j++) {
			if (visited[j] == 1)
				continue;

			pair<int, int> p1 = home[i];
			pair<int, int> p2 = bbq[j];

			tmp = min(tmp,(abs(p1.first - p2.first) + abs(p1.second - p2.second)));
		}
		total = total + tmp;
	}

	answer = min(answer, total);

	return;
}

void dfs(int start, int cnt) {

	if(cnt==(bbq_cnt-m)){
		
		init();
		distance();
		return;
	}

	for (int i = start; i < bbq.size(); i++) {
		if (visited[i] == 1)
			continue;
		
		visited[i] = 1;
		v.push_back(i);
		dfs(i, cnt + 1);
		v.pop_back();
		visited[i] = 0;
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

			if (map[i][j] == 1) {
				home.push_back(pair<int, int>(i,j));
			}

			else if (map[i][j] == 2) {
				bbq.push_back(pair<int, int>(i,j));
				bbq_cnt++;
			}
		}
	}

	dfs(0, 0);

	cout << answer;

	return 0;
}