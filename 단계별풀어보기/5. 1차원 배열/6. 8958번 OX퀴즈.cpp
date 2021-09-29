#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		string input;
		cin >> input;
		
		int cnt = 0;
		int score = 0;

		for (int j = 0; j < input.size(); j++) {

			if (input[j] == 'O') {
				cnt++;
				score += cnt;
			}
			else if (input[j] == 'X') {
				cnt = 0;
			}
		}

		cout << score << '\n';
	}

	return 0;
}