#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int solution(string s) {
	int answer = s.size();
	cout << s << endl << endl;
	for (int len = 1; len < s.size(); len++) {	//½ºÇÃ¸´ ±æÀÌ
		int res = 0;
		string test;
		queue<pair<string, int>> q;
		q.push({ s.substr(0, len),0 });

		int check = 0;
		while (!q.empty()) {
			string cur = q.front().first;
			int idx = q.front().second;
			q.pop();
			int cnt = 0;
			for (int i = idx; i < s.size(); i += cur.size()) {
				string tmp = s.substr(i, cur.size());
				if (cur != tmp) {
					q.push({ tmp,i });
					break;
				}
				else {
					cnt++;
				}
			}
			if (cnt > 1) {
				test += to_string(cnt);
				res += to_string(cnt).size();
			}
			test += cur;
			
			res += cur.size();
		}
		
		answer = min(res, answer);
		//cout << test << endl;

	}
	return answer;
}
int main() {
	cout << solution("aabbaccc") << endl;
	cout << solution("ababcdcdababcdcd") << endl;
	cout << solution("abcabcdede") << endl;
	cout << solution("abcabcabcabcdededededede") << endl;
	cout << solution("xababcdcdababcdcd") << endl;
	return 0;
}