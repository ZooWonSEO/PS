#include <iostream>
using namespace std;

int main() {

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (input < x) {
			cout << input << " ";
		}

	}
	

	return 0;
}