#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {

	string jobs[5] = { "SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME" };
	map<string, int> m;
	map<string, int>::iterator it;
	int score[5] = { 0, };

	for (int i = 0; i < preference.size(); i++) {
		m[languages[i]] = preference[i];
	}

	for (int i = 0; i < table.size(); i++) {

		string tmp = "";
		vector<string> v;
		
		for (int j = 0; j < table[i].size(); j++) {
			if (table[i][j] == ' ') {
				v.push_back(tmp);
				tmp = "";
			}
			else {
				tmp = tmp + table[i][j];
			}
		}
		v.push_back(tmp);

		for (int j = 1; j < v.size(); j++) {
			if (m.find(v[j]) != m.end()) {
				score[i] = score[i] + (m[v[j]] * (6 - j));
			}
		}
	}
	
	int mx = 0;
	for (int i = 0; i < 5; i++) {
		mx = max(mx, score[i]);
	}	

	vector<string> answer;
	for (int i = 0; i < 5; i++) {
		if (score[i] == mx) {
			answer.push_back(jobs[i]);
		}
	}

	sort(answer.begin(), answer.end());
	
	return answer[0];
}

int main(void)
{

	vector<string> table = { 
		"SI JAVA JAVASCRIPT SQL PYTHON C#",
		"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
		"HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
		"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
		"GAME C++ C# JAVASCRIPT C JAVA" };

	/*
	vector<string> languages = {
		"PYTHON",
		"C++",
		"SQL"
	};

	vector<int> preference = {
		7,
		5,
		5
	};
	*/
	// HARDWARE


	vector<string> languages = {
		"JAVA",
		"JAVASCRIPT"
	};

	vector<int> preference = {
		7,
		5
	};
	// PORTAL

	cout << solution(table, languages, preference) << "\n";

	return 0;
}