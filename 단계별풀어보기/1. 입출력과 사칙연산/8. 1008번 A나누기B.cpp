#include <iostream>
using namespace std;

/*
소수점 정하는 문제 : cout.precision, cout << fixed
*/

int main() {
	
	double a, b;
	cin >> a >> b;
	cout.precision(9);
	cout << fixed;
	cout << a / b;

	return 0;
}