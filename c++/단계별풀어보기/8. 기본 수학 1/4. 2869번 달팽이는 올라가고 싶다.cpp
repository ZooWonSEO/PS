#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	double a, b, v;
	cin >> a >> b >> v;

	double ans = 0;
	cout << (int)ceil((v - b) / (a - b));

	return 0;
}