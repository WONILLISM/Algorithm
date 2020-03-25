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

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	queue<PII> q;
	for (int i = 0; i < food_times.size(); i++)
		q.push({ i + 1,food_times[i] });

	while (q.size() != 0 && k > 0) {	// 남은 음식이 없거나 , 시간이 다 했으면 종료
		ll size = q.size();
		ll eat = k / size;
		k %= size;	// 한 번에 먹을 수 있는 양 제외하고 남음

		if (eat == 0)break;	// 더 이상 한 번에 먹을 수 없으면 종료

		ll rest = 0;
		for (int i = 0; i < size; i++) {
			PII a = q.front();
			q.pop();
			a.second -= eat;
			if (a.second <= 0)	// 음식을 다 먹었다면
				rest -= a.second;	// 초과된 시간 만큼 저장
			else
				q.push(a);
		}
		k += rest;
	}
	if (q.empty())return -1;	// 더 이상 남은 음식이 없으면
	else {
		if (k > 0) {			// 시간이 남았다면
			while (!q.empty()) {	// 시간이 끝날 때 그때의 idx를 반환
				--k;
				if (k == -1)return q.front().first;
				q.pop();
			}
		}
		else return q.front().first;
	}
	
	return answer;
}
int main() {
	cout << solution({ 3,1,2 }, 5) << endl;
	return 0;
}