#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>

using namespace std;

priority_queue<int,vector<int>,greater<int>> wait;
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	int start = 540;	// ��� �ð�
	int curtime = 0;	
	int curbus = 1;
	int go = 0;

	// �� ���� ��ȯ �� �켱���� ť�� ����
	for (int i = 0; i < timetable.size(); i++) {
		string str = timetable[i].substr(0,2);
		int tmp = stoi(str) * 60;
		str = timetable[i].substr(3, 5);
		tmp += stoi(str);
		
		wait.push(tmp);
	}
	
	while (curbus <= n) {
		if (wait.empty()) {	// ����� ���� ��
			curtime = 540 + t * (n - 1);	// ������ �� Ÿ��
			break;
		}
		else {		// ����� ���� ��
			if (start < wait.top()) {	// Ż �� ���� ����ڶ��
				if (curbus == n) {
					curtime = 540 + t * (n - 1);
					break;
				}
				start += t;	// ���� ����
				curbus++;
				go = 0;
			}
			else {			// Ż �� �ִ� �����
				if (go == m - 1 && curbus == n) {
					curtime = wait.top() - 1;	// 1�� ���� ���� Ż �� ����
					break;
				}
				wait.pop();
				go++;
			}
		}
		if (go == m) { //���� á���� ���� ����
			start += t;
			curbus++;
			go = 0;
		}
	}
	
	if (curtime / 60 >= 10)
		answer += to_string(curtime / 60);
	else {
		answer += "0";
		answer += to_string(curtime / 60);
	}
	answer += ":";

	if (curtime % 60 >= 10)
		answer += to_string(curtime % 60);
	else {
		answer += "0";
		answer += to_string(curtime % 60);
	}
	return answer;
}
int main() {
	// n ���� Ƚ��, t ���� ����, m ���� �ο�, ũ�� �����ð�
	for (auto ans : solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" })) {
		cout << ans  ;
	}
	//for (auto ans : solution(2, 10, 2, { "09:10", "09:09", "08:00"})) {
	//	cout << ans;
	//}
	return 0;
}