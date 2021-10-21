#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	
	if (n % 5 == 0) {
		cout << n / 5;
	}
	else {
		int three = 0;
		int five = 0;

		while (n % 5 != 0) {
			
			n = n - 3;
			three++;
			
			if (n < 3 && n!=0) {
				cout << -1;
				return 0;
			}
		}
		five = n / 5;
		cout << three + five;
	}

	return 0;
}