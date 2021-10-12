#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	priority_queue<int> pq;

	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				int num = 0;
				num = pq.top();
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