#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
const int INF = 1 << 30;
int N, E, v1, v2;
typedef struct graph {
	int v, step;

	bool operator<(const graph &n)const {
		return step > n.step;
	}
};
vector<vector<graph>> G;
vector<int> visit;
typedef struct point {
	int v, step;
	bool operator<(const point &n)const {
		return step > n.step;
	}
};
int process(int start, int end) {
	priority_queue<graph> pq;
	pq.push({ start, 0 });
	visit.assign(N, INF);
	visit[start] = 0;
	while (!pq.empty()) {
		int v = pq.top().v, step = pq.top().step;
		pq.pop();
		if (visit[v] >= step) {
			for (int i = 0; i < G[v].size(); i++) {
				int next = G[v][i].v, nStep = G[v][i].step;
				if (visit[next] > nStep + step) {
					visit[next] = nStep + step;
					pq.push({ next, visit[next] });
				}
			}
		}
	}
	//printf("%d->%d = %d\n",start, end, visit[end]);
	return visit[end];
}
void solution() {
	
	int p1 = process(0, v1 - 1) + process(v1 - 1, v2 - 1) + process(v2 - 1, N - 1);
	int p2 = process(0, v2 - 1) + process(v2 - 1, v1 - 1) + process(v1 - 1, N - 1);

	if (p1 < p2&&p1 < INF)printf("%d\n", p1);
	else if (p1 > p2&&p2 < INF)printf("%d\n", p2);
	else printf("-1\n");
}
int main() {
	scanf("%d %d", &N, &E);
	G.assign(N, vector<graph>());
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u - 1].push_back({ v - 1,w });
		G[v - 1].push_back({ u - 1,w });
	}
	scanf("%d%d", &v1, &v2);
	solution();
	return 0;
}