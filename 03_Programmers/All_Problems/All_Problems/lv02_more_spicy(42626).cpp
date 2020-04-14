#include<iostream>
#include <string>
#include <vector>
#include<queue>
#define ll long long

using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int size = scoville.size();
	priority_queue <int, vector<int>, greater<int> > pq;
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	while (pq.top() < K && size > 1) {
		int tmp1 = pq.top();
		pq.pop();
		int tmp2 = pq.top();
		pq.pop();
		int tmp3 = tmp1 + tmp2 * 2;
		pq.push(tmp3);
		answer++;
		size = pq.size();
	}


	if (pq.top() < K)
		answer = -1;
	return answer;
}
int main() {
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7) << endl;
	return 0;
}