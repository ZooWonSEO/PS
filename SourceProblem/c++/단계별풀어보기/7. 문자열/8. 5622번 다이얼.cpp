#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int arr[10] = { 0,2,3,4,5,6,7,8,9,10 };
	arr[0] = arr[9] + 1;

	int alpha[8] = { 3,3,3,3,3,4,3,4 };
	int cnt = 2;
	
	int ch[26];
	int idx = 0;
	for (int i = 0; i < 8; i++) {
		int tmp = alpha[i];
		for (int j = 0; j < tmp; j++) {
			ch[idx] = cnt;
			idx++;
		}
		cnt++;
	}
	
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = ans + arr[ch[s[i] - 'A']];
	}
	
	cout << ans;

	return 0;
}