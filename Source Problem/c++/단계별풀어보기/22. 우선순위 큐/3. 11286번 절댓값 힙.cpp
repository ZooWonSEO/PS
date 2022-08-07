#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, comp> pq;

	while (n--) {
		int x = 0;
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
		else {
			pq.push(x);
		}
	}

	return 0;
}