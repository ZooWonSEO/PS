#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {

	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp > pq;

	while (n--) {

		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				int num = pq.top();
				pq.pop();
				cout << num << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (x > 0) {
			pq.push(x);
		}
	}

	return 0;
}