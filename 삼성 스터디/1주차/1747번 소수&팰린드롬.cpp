#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
풀이법
0. 에라토스테네스의 체와, to_string을 사용해 풀었다.
1. 처음에는 백만이 넘어갈때, 팰린드롬 소수를 출력하지 않아도 되는줄 알았다.
2. 1003001을 출력해 줘야한다. ㅋㅋㅋ.
*/

int prime[1004000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < 1004000; i++) {
		prime[i] = 1;
	}

	for (int i = 2; i <= sqrt(1004000); i++) {
		for (int j = i + i; j < 1004000; j = j + i) {
			// 이미 소수가 아님이 판별 났다면
			if (prime[j] == 0)
				continue;
			prime[j] = 0;
		}
	}

	prime[0] = 0;
	prime[1] = 0;

	for (int i = n; i < 1004000; i++) {

		// 소수가 아니면 통과
		if (prime[i] == 0)
			continue;

		string str = to_string(i);
		int left = 0;
		int right = str.size() - 1;
		bool check = true;

		while (left <= right) {
			if (str[left] != str[right]) {
				check = false;
				break;
			}
			left++;
			right--;
		}

		if (check == true) {
			cout << i;
			break;
		}
	}

	return 0;
}