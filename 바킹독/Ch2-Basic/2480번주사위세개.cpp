#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int total = 0;
	vector<int> v;

	for (int i = 0; i < 3; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	
	sort(v.begin(), v.end());

	if (v[0] == v[1] && v[1] == v[2]) {
		total = 10000 + (v[2] * 1000);
	}

	else if (((v[0] == v[1]) && (v[1] != v[2])) || ((v[1] == v[2]) && (v[1] != v[0]))) {
		total = 1000 + (v[1] * 100);
	}

	else {
		total = v[2] * 100;
	}

	cout << total;

	return 0;
}