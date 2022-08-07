#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cin >> s;

	int cnt = 0;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i + 1] == '=') {
			if (s[i] == 'c' || s[i] == 's') {
				i++;
			}
			else if (s[i] == 'z') {
				if (i - 1 >= 0) {
					if (s[i - 1] == 'd') {
						cnt --;
						i++;
					}
					else {
						i++;
					}
				}
				else {
					i++;
				}
			}
		}
		else if (s[i + 1] == '-') {
			if (s[i] == 'c' || s[i] =='d') {
				i++;
			}
		}
		else if (s[i + 1] == 'j') {
			if (s[i] == 'l' || s[i] == 'n') {
				i++;
			}
		}

		cnt++;
	}

	cout << cnt;

	return 0;
}