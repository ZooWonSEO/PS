#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	int x = -1;

	if (c - b <= 0) {
		x = -1;
	}
	else{
		x = a / (c - b) + 1;
	}
	
	cout << x;

	return 0;
}