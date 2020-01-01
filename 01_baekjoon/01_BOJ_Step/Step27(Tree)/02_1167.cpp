#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;
int V, Max;
struct NodeI { int v, dist; };
vector<vector<NodeI>> g;
vector<int> visit;
struct Pos { 
	int v, d; 
	bool operator < (const Pos &n)const {
		return d < n.d;
	}
};

void input() {
	for (int i = 0; i < V; i++) {
		int u, v, d;
		scanf("%d", &u);
		do {
			scanf("%d", &v);
			if (v != -1) {
				scanf("%d", &d);
				g[u - 1].push_back({ v - 1,d });
				g[v - 1].push_back({ u - 1,d });
			}
		} while (v != -1);
	}
}
void process(int start) {
	priority_queue<Pos> pq;
	visit.assign(V, 0);
	pq.push({ start,0 });
	visit[start] = -1;
	while (!pq.empty()) {
		Pos cur = pq.top(); pq.pop();
		for (int i = 0; i < g[cur.v].size(); i++) {
			int n = g[cur.v][i].v, nd = g[cur.v][i].dist;
			if (!visit[n]) {
				visit[n] = cur.d + nd;
				pq.push({ n, visit[n] });
				if (Max < visit[n])Max = visit[n];
			}
		}
	}
}
void solution() {
	scanf("%d", &V);
	g.assign(V, vector<NodeI>());
	input();
	process(0);
	printf("%d\n", Max);
}
int main() {
	freopen("02.in", "r", stdin);
	solution();
	return 0;
}