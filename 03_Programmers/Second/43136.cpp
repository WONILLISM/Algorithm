#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int visit[20001];
int solution(int n, vector<vector<int>> edge) {
	int answer = 0, t = 0;
	vector<vector<int>> graph(n + 1, vector<int>());
	//vector<bool> visit(n+1, false);
	for (int i = 0; i < edge.size(); i++) {
		int u = edge[i][0], v = edge[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<pair<int, int>> q;

	q.push({ 1,1 });
	visit[1] = 1;

	while (!q.empty()) {
		int cur = q.front().first, cur_step = q.front().second;
		q.pop();
		if (cur_step > t)t = cur_step;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visit[next]) {
				visit[next] = cur_step + 1;
				q.push({ next, cur_step + 1 });
			}
		}
	}
	for (auto a : visit)
		if (t == a)answer++;
	return answer;
}