#include <iostream>
using namespace std;

int main() {
	
	int x;
	cin >> x;

	int num = 1;
	int line = 1;

	while (1) {

		if (num > x) {
			line--;
			break;
		}

		num = num + line;
		line++;
	}

	int gap = num - x;

	if (line % 2 == 0) {
		cout << line - gap +1 << "/" << gap;
	}
	else {
		cout << gap << "/" << line - gap + 1;
	}

	return 0;
}