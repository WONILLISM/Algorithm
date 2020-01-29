#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	for (int i = 0; i < operations.size(); i++) {
		string s = operations[i];
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
	vector<string> opr;
	opr.push_back("I 7");
	opr.push_back("I 5");
	opr.push_back("I -5");
	opr.push_back("D -1");
	for (auto a : solution(opr))
		cout << a;
	
	return 0;
}