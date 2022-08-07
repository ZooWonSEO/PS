#include <iostream>
#include <string>
using namespace std;

int main() {

	int ans = 0;
	string input;
	int n;

	cin >> n;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		ans = ans + (int)input[i] - '0';
	}

	cout << ans;
	
	return 0;
}