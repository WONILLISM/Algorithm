#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;
int N;
vector<vector<int>> g;
vector<bool> visit;
vector<int> p;
void process(int v) {
	
	visit[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int next = g[v][i];
		if (!visit[next]) {
			p[next] = v;
			process(next);
		}
	}
}
void solution() {
	scanf("%d", &N);
	g.assign(N+1, vector<int>());
	visit.assign(N + 1, false);
	p.assign(N + 1, 0);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	process(1);
	for (int i = 2; i <= N; i++)
		printf("%d\n", p[i]);
}
int main() {
	solution();
	return 0;
}