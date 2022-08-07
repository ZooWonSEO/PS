#include <iostream>
using namespace std;

/*
while의 종료조건이 없는 문제였다.
while 조건에 cin을 받으면 해결된다.
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;

	while (cin >> a>> b) {
		cout << a + b << '\n';
	}
	
	return 0;
}