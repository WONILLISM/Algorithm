#include<iostream>
#include<string>
#include <vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++) {
		//string s = operations[i].substr(1, operations[i].size() - 1);
		string s = operations[i];
		//int a = atoi(s.c_str());
		int a = stoi(s.substr(2));
		if (operations[i][0] == 'I') {
			dq.push_back(a);
			sort(dq.begin(), dq.end());
		}
		else if (operations[i][0] == 'D') {
			if (!dq.empty()) {
				if (a == 1)dq.pop_back();
				else if (a == -1)dq.pop_front();
			}
		}
	}
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		int M = dq.back(), m = dq.front();
		answer.push_back(M);
		answer.push_back(m);
	}
	return answer;
}
int main() {
	vector<string> o;
	o.push_back("I 7");
	o.push_back("I 5");
	o.push_back("I -5");
	o.push_back("D -1");
	
	vector<int> ans = solution(o);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}