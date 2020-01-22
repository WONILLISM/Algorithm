#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

//작업시간이 가장 작은 것 먼저
struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};
int solution(vector<vector<int>> jobs) {
	int answer = 0, idx = 0, time = 0;
	//요청시간이 빠른 순서로 정렬
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //우선순위 큐 min heap
	//대기열이 없고 우선순위 큐가 빌때까지 반복
	while (idx < jobs.size() || !pq.empty()) {
		//들어올 대기열이 남아있고, 디스크시간보다 작거나 같다면
		if (jobs.size() > idx && time >= jobs[idx][0]) {
			//우선순위 큐에 추가
			pq.push(jobs[idx++]);
			//인덱스 증가
			//같은시간대에 다른작업 다시 확인
			continue;
		}
		//큐가 비어있지 않다면
		if (!pq.empty()) {
			//시간에 이작업이 끝날때까지 걸리는 시간만큼 추가
			time += pq.top()[1];
			//작업시간에 대기 시간만큼 추가(현재시간 - 들어온 시간)
			answer += time - pq.top()[0];
			//작업 종료
			pq.pop();
		}
		else //큐가 비어있다면 다음작업 시간으로 넘김
			time = jobs[idx][0];
	}
	return answer / jobs.size();
}
int main(){
	cout << solution({ {0,3},{1,9},{2,6} });
	return 0;
}