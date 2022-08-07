#include <iostream>
using namespace std;

int arr[10002] = { 0, };

void d(int input) {

	if (input >= 10000)
		return;

	int total = 0;
	total = total + input;
	while (input > 0) {
		total = total + (input % 10);
		input = input / 10;
	}

	if (total < 10000) {
		if (arr[total] == 0) {
			arr[total] = 1;
		}
		return d(total);
	}
	else {
		return;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 10000; i++) {
		if (arr[i] == 1)
			continue;
		d(i);
	}

	for (int i = 1; i < 10000; i++) {
		if (arr[i] == 1)
			continue;
		cout << i << '\n';
	}

	return 0;
}