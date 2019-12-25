#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
const int INF = 1 << 30;
int V, E, Start, ans;
typedef struct graph {
	int v, step; 
	bool operator<(const graph &n)const {
		return step > n.step;
	}
};
vector<vector<graph>> G;

void solution() {
	priority_queue<graph> pq;
	vector<int> visit(V, INF);
	pq.push({ Start - 1, 0 });
	visit[Start-1] = 0;
	while (!pq.empty()) {
		int v = pq.top().v, step = pq.top().step;
		pq.pop();
		for (int i = 0; i < G[v].size(); i++) {
			int n = G[v][i].v, nStep = G[v][i].step;
			if (visit[n]>step + nStep) {
				visit[n] = step + nStep;
				pq.push({ n,visit[n] });
			}
		}
	}
	for (int i = 0; i < visit.size(); i++) {
		if (visit[i] == INF)printf("INF\n");
		else printf("%d\n", visit[i]);
	}
}
int main() {
	scanf("%d %d %d", &V, &E, &Start);
	vector<vector<graph>> g(V, vector<graph>());
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u - 1].push_back({ v - 1,w });
	}
	G = g;
	solution();
	return 0;
}