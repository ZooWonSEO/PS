#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int cnt = 1;
	int num = 0;
	int tmp1 = 0; // 일의 자리
	int tmp2 = 0; // 십의 자리

	tmp1 = n % 10;
	tmp2 = (n / 10) % 10;
	num = tmp1 * 10 + ((tmp1 + tmp2)%10);

	while (num != n) {
		
		tmp1 = num % 10;
		tmp2 = (num / 10) % 10;
		num = tmp1 * 10 + ((tmp1 + tmp2) % 10);
		cnt++;
	}

	cout << cnt;
	
	return 0;
}