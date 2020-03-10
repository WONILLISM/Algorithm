#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define PIS pair<int,string>

using namespace std;
const int INF = 1 << 30;
vector<PII> graph[51];
int visit[51];
void process(int s) {
	visit[s] = 0;
	priority_queue<PII> pq;
	pq.push({ s,0 });

	while (!pq.empty()) {
		int cur = pq.top().first, cost = pq.top().second;
		pq.pop();

		if (visit[cur]>=cost) {
			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i].first, nCost = cost + graph[cur][i].second;
				if (nCost < visit[next]) {
					visit[next] = nCost;
					pq.push({ next, nCost });
				}
			}
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
	int ans = 0;
	for (int i = 0; i < N + 1; i++)
		visit[i] = INF;
	// 인접 리스트를 이용한 그래프
	for (int i = 0; i < road.size(); i++) {
		int u = road[i][0], v = road[i][1];
		int cost = road[i][2];
		graph[u].push_back({ v,cost });
		graph[v].push_back({ u,cost });
	}
	// 다익스트라
	process(1);

	for (int i = 1; i <= N; i++) {
		if (visit[i] <= K) {
			ans++;
		}
	}
	return ans;
}
int main() {
	cout << solution(5, { {1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2} }, 3) << endl;
	return 0;
}