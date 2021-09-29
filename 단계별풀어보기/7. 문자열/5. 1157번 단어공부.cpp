#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int arr[26] = { 0, };

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			arr[s[i] - 'a'] ++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			arr[s[i] - 'A'] ++;
		}
	}

	int mx = 0;
	int cnt = 0;
	int idx = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > mx) {
			mx = arr[i];
			cnt = 1;
			idx = i;
		}
		else if (arr[i] == mx) {
			cnt++;
		}
	}

	if (cnt == 1) {
		cout << (char)toupper('a' + idx);
	}
	else {
		cout << '?';
	}

	return 0;
}