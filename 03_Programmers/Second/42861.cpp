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
using namespace std;

const int MAX = 101;
const int INF = 1 << 31;

vector<PII> graph[MAX];  // i 노드가 출발지인 간선들, first 비용, second 목적지
priority_queue<PII, vector<PII>, greater<PII>> pq; // 선택될 가능성이 있는 간선들
bool visit[MAX];
int ans;
void prim(int v) {
	visit[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		PII a = graph[v][i];
		if (!visit[a.second]) {
			pq.push(a);
		}
	}
	while (!pq.empty()) {
		PII a = pq.top(); pq.pop();
		if (!visit[a.second]) {
			ans += a.first;
			prim(a.second);
			return;
		}
	}
}
int solution(int n, vector<vector<int>> costs) {
	for (auto c : costs) {
		int u = c[0], v = c[1], cost = c[2];
		graph[u].push_back({ cost, v });
		graph[v].push_back({ cost, u });
	}
	prim(0);
	return ans;
}
int main() {
	vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};
	cout << solution(4, costs) << endl;
	return 0;
}