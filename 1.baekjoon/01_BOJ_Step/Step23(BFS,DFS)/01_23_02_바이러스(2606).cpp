#include<cstdio>

using namespace std;
int ans;
int network[101][101];
int visit[101];
int Q[101];
int f, r;
void push(int x) { Q[r++] = x; }
int pop() { return Q[f++]; }
int solution(int n) {
	int cur = 1;
	visit[cur] = 1;
	push(cur);
	while (f != r) {
		cur = pop();
		for (int i = 1; i <= n; i++) {
			if (!visit[i]&&network[cur][i]) {
				visit[i] = 1;
				push(i);
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		network[u][v] = 1;
		network[v][u] = 1;
	}
	printf("%d\n", solution(n));

	return 0;
}