#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
풀이법
0. 재귀를 사용한 조합을 구현해 완탐으로 품
*/

int l, c;
char arr[16];
int visited[16];
vector<char> v;

void dfs(int start) {

	if (v.size() == l) {
		
		int ja = 0;
		int mo = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
				mo++;
			}
			else {
				ja++;
			}
		}

		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << '\n';
		}
	}

	for (int i = start; i < c; i++) {
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		v.push_back(arr[i]);
		dfs(i + 1);
		v.pop_back();
		visited[i] = 0;
	}
}

int main() {

	cin >> l >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + c);

	dfs(0);

	return 0;
}