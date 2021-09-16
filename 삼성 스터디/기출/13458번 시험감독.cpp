#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

	long long n;
	vector<long long> v;
	long long b, c;
	long long total = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}

	cin >> b >> c;

	for (int i = 0; i < v.size(); i++) {
		double cur = v[i];
		cur = cur - b;
		total = total + 1;

		if (cur > 0) {
			total = total + ceil(cur / c);
		}
	}

	cout << total;

	return 0;
}