#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;
	int cur = 0;
	while (stock < k) {
		for (int i = cur; i < dates.size(); i++) {
			if (dates[i] <= stock) {			// 남아있는 기간 보다 짧거나 같은 경우만 pq에 푸시
				pq.push(supplies[i]);
				cur = i + 1;
			}
			else {
				break;	// 받아야 한다면 날짜 변경	
			}
			
		}
		answer++;	// 밀가루 받음
		stock += pq.top();
		pq.pop();
	}
	return answer;
}
int main() {
	//cout << solution(4, { 4,10,15 }, { 20,5,10 }, 30) << endl;
	cout << solution(4, { 1,2,3,4 }, { 10,40,20,30 }, 100) << endl;
	return 0;
}
