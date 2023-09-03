#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int cnt;
	vector<int> arr;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	if (cnt == 1) {
		cout << arr[0] * arr[0];
	}
	else {
		cout << arr[0] * arr[arr.size() - 1];
	}


	return 0;
}