#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {

	int sz = enter.size();
	vector<int> answer(sz);
	
	set<int> room;
	set<int>::iterator it;
	map<pair<int, int>, int > m;
	int l_idx = 0;
	int e_idx = 0;

	while (l_idx < sz) {
		
		int cur_person = leave[l_idx];
		
		while (room.find(cur_person) == room.end()) {
			room.insert(enter[e_idx]);
			e_idx++;
		}

		while (l_idx < sz && room.find(cur_person) != room.end()) {
			
			answer[cur_person-1] += room.size() - 1;
			room.erase(cur_person);

			for (it = room.begin(); it != room.end(); it++) {

				answer[*it - 1] = answer[*it - 1] + 1;
			}

			l_idx++;
		}
	}

	return answer;
}
	
int main(void)
{
	
	vector<int> enter = { 1, 4, 2, 3 };
	vector<int> leave = { 2, 1, 3, 4 };
	//[2, 2, 1, 3]

	//vector<int> enter = { 1, 3, 2 };
	//vector<int> leave = { 1, 2, 3 };
	//[0, 1, 1]

	//vector<int> enter = { 3, 2, 1 };
	//vector<int> leave = { 2, 1, 3 };
	//[1, 1, 2]

	//vector<int> enter = { 3, 2, 1 };
	//vector<int> leave = { 1, 3, 2 };
	// [2, 2, 2]

	//vector<int> enter = { 1, 4, 2, 3 };
	//vector<int> leave = { 2, 1, 4, 3 };
	// [2, 2, 0, 2]

	vector<int> answers = solution(enter, leave);

	for (int answer : answers)
	{
		cout << answer << " ";
	}

	cout << "\n";

	return 0;
}