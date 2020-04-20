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
			if (dates[i] <= stock) {			// �����ִ� �Ⱓ ���� ª�ų� ���� ��츸 pq�� Ǫ��
				pq.push(supplies[i]);
				cur = i + 1;
			}
			else {
				break;	// �޾ƾ� �Ѵٸ� ��¥ ����	
			}
			
		}
		answer++;	// �а��� ����
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
