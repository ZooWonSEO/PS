#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	int tmp = a * b * c;
	
	int arr[10] = { 0, };
	
	while (tmp > 0) {
		arr[tmp % 10]++;
		tmp = tmp / 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}