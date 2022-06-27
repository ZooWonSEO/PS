#include <iostream>
#include <string>
using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	int num1 = (int)(s1[2] - '0') * 100 + (int)(s1[1] - '0') * 10 + (int)s1[0] - '0';
	int num2 = (int)(s2[2] - '0') * 100 + (int)(s2[1] - '0') * 10 + (int)s2[0] - '0';

	if (num1 > num2) {
		cout << num1;
	}
	else {
		cout << num2;
	}

	return 0;
}