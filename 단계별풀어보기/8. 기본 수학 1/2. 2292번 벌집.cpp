#include <iostream>
using namespace std;

// 계차수열!!

long long n;

int main() {

	cin >> n;

	long long room = 1;
	bool check = true;
	long long answer = 0;

	if (n == 1) {
		cout << 1;
	}

	else {
		while (check) {

			long long cur = room;
			long long cur2 = room + 1;

			long long tmp = 3 * (cur*cur) - (3*cur) + 2;
			long long tmp2 = 3 * (cur2*cur2) - (3*cur2) + 2;
			tmp2--;

			if (n>= tmp && n <=tmp2) {
				check = false;
				answer = cur;
				break;
			}
			room++;
		}
		cout << answer+1;
	}
	return 0;
}