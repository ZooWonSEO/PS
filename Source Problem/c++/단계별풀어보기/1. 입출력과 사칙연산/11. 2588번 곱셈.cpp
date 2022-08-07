#include <iostream>
using namespace std;

int main() {
	
	int a, b;
	cin >> a >> b;

	int tmp = b;
	while (tmp > 0) {
		cout << a*(tmp % 10) << '\n';
		tmp = tmp / 10;
	}

	cout << a * b;

	return 0;
}