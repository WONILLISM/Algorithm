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

	int start = 540;	// 출발 시각
	int curtime = 0;	
	int curbus = 1;
	int go = 0;

	// 분 단위 변환 후 우선순위 큐에 저장
	for (int i = 0; i < timetable.size(); i++) {
		string str = timetable[i].substr(0,2);
		int tmp = stoi(str) * 60;
		str = timetable[i].substr(3, 5);
		tmp += stoi(str);
		
		wait.push(tmp);
	}
	
	while (curbus <= n) {
		if (wait.empty()) {	// 대기자 없을 때
			curtime = 540 + t * (n - 1);	// 마지막 차 타기
			break;
		}
		else {		// 대기자 있을 때
			if (start < wait.top()) {	// 탈 수 없는 대기자라면
				if (curbus == n) {
					curtime = 540 + t * (n - 1);
					break;
				}
				start += t;	// 다음 버스
				curbus++;
				go = 0;
			}
			else {			// 탈 수 있는 대기자
				if (go == m - 1 && curbus == n) {
					curtime = wait.top() - 1;	// 1분 일찍 오면 탈 수 있음
					break;
				}
				wait.pop();
				go++;
			}
		}
		if (go == m) { //가득 찼으면 다음 버스
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
	// n 운행 횟수, t 배차 간격, m 수용 인원, 크루 도착시간
	for (auto ans : solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" })) {
		cout << ans  ;
	}
	//for (auto ans : solution(2, 10, 2, { "09:10", "09:09", "08:00"})) {
	//	cout << ans;
	//}
	return 0;
}