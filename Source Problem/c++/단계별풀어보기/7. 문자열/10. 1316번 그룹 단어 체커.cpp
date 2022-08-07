#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 0;
	int arr[26] = { 0, };

	for (int i = 0; i < n; i++) {

		string s;
		cin >> s;
		
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}

		bool check = true;
		for (int j = 0; j < s.size()-1; j++) {
			if (s[j] == s[j + 1]) {
				arr[s[j] - 'a']++;
			}
			else {
				if (arr[s[j+1]-'a'] > 0) {
					check = false;
					break;
				}
				arr[s[j] - 'a']++;
			}
		}

		if (check == true) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}