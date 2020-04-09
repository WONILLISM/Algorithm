#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define PII pair<int, int>
using namespace std;

queue<PII> q;
int answer, curWeight, curTime;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	q.push({ truck_weights[0], 1 });
	curWeight += truck_weights[0];
	answer++;
	for (int i = 1; i < truck_weights.size(); i++) {
		int next = truck_weights[i];	//다음 대기중 트럭
		answer++;		// 현재 트릭 1칸 움직임
		curTime = q.front().second;	
		if (answer - curTime == bridge_length) {	// 다리 통과 처리
			curWeight -= q.front().first;
			q.pop();
		}
		if (curWeight + next <= weight) {	// 대기중 트럭이 다리의 무게를 견디면 푸시
			curWeight += next;
			q.push({ next, answer });
		}
		else i--;	// 대기중 트럭 그대로 대기, 현재트럭 진행
	}

	while (!q.empty()) {	// q에 남아있는 트럭들 처리
		answer++;
		curTime = q.front().second;
		if (answer - curTime == bridge_length) {
			curWeight -= q.front().first;
			q.pop();
		}
	}


	return answer;
}
int main() {
	cout << solution(2, 10, { 7,4,5,6 }) << endl;
	return 0;
}