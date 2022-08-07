#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visited[100002];

int main() {
	
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 100002; i++) {
		visited[i] = 0;
	}

	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (!q.empty()) {
		int cur_pos = q.front();
		q.pop();

		if (cur_pos == k)
			break;

		for (int i = 0; i < 3; i++) {

			int next_pos = 0;
			
			if (i == 0) {
				next_pos = cur_pos +1;
			}
			else if (i == 1) {
				next_pos = cur_pos *2;
			}
			else if (i == 2) {
				next_pos = cur_pos - 1;
			}

			if (next_pos < 0 || next_pos >= 100001)
				continue;
			
			if (visited[next_pos] == 0) {
				visited[next_pos] = visited[cur_pos] + 1;
				q.push(next_pos);
			}
			
		}
	}

	cout << visited[k]-1;

	return 0;
}