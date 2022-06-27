#include <iostream>
#include <algorithm>
using namespace std;

/*
풀이법
1. 9명의 난쟁이 키를 저장하면서 total에 합을 구한다.
2. 2명씩 빼며 100이 되는 순간을 찾아서, 해당 idx들을 -1로 바꾼다.
3. 오름차순 정렬 후, 출력한다.
*/

int main() {

	int arr[9];
	int total = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		total = total + arr[i];
	}

	bool check = true;

	for (int i = 0; i < 8; i++) {
		
		if (check == false)
			break;
		
		for (int j = i + 1; j < 9; j++) {
			if ((total - arr[i] - arr[j]) == 100) {
				arr[i] = -1;
				arr[j] = -1;
				check = false;
			}
		}
	}
	
	sort(arr, arr + 9);

	for (int i = 2; i < 9; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}