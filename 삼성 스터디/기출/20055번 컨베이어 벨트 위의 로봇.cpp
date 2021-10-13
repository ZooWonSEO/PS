#include <iostream>
#include <deque>
using namespace std;

int n, k;
deque<int> negu;
deque<int> robot;

int answer = 0;

bool check() {

	int zero_cnt = 0;

	for (int i = 0; i < negu.size(); i++) {
		if(negu[i]<=0){
			zero_cnt++;
		}
	}

	if (zero_cnt >= k)
		return true;
	else
		return false;
}

void rotate() {
	
	negu.push_front(negu.back());
	negu.pop_back();

	robot.push_front(robot.back());
	robot.pop_back();
	

	// 회전 즉시 robot drop
	robot[n - 1] = 0;

	return;
}

void move() {

	for (int i = n - 2; i >= 0; i--) {
		if (robot[i] == 1) {
			if (robot[i + 1] == 0 && negu[i + 1] > 0) {
				robot[i + 1] = 1;
				negu[i + 1] --;
				robot[i] = 0;
			}
		}
	}
	
	// move 즉시 robot drop
	robot[n - 1] = 0;

	return;
}

void put_robot() {

	if (negu[0] > 0) {
		robot[0] = 1;
		negu[0] --;
	}
return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n * 2; i++) {
		int input;
		cin >> input;
		negu.push_back(input);
		robot.push_back(0);
	}

	while (1) {

		// 0. 단계 설정
		answer++;

		// 1. 회전
		rotate();
	

		// 2. 로봇 움직이기
		move();

		// 3. 로봇 올리기
		put_robot();

		// 4. 단계 수행 가능 여부 확인하기
		bool stop = check();
		if (stop)
			break;
	}

	cout << answer;

	return 0;
}