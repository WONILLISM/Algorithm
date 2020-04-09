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
		int next = truck_weights[i];	//���� ����� Ʈ��
		answer++;		// ���� Ʈ�� 1ĭ ������
		curTime = q.front().second;	
		if (answer - curTime == bridge_length) {	// �ٸ� ��� ó��
			curWeight -= q.front().first;
			q.pop();
		}
		if (curWeight + next <= weight) {	// ����� Ʈ���� �ٸ��� ���Ը� �ߵ�� Ǫ��
			curWeight += next;
			q.push({ next, answer });
		}
		else i--;	// ����� Ʈ�� �״�� ���, ����Ʈ�� ����
	}

	while (!q.empty()) {	// q�� �����ִ� Ʈ���� ó��
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