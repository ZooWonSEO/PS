#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void dfs(int start, int cnt) {

	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {

		v.push_back(i);
		dfs(i, cnt+1);
		v.pop_back();
	}
	return;
}

int main() {
	
	cin >> n >> m;
	dfs(1, 0);
	
	return 0;
}