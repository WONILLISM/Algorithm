#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1 << 30;
const int MAX = 16;
int N, ans;
int cost[MAX][MAX];
int dp[MAX][1 << MAX];

int process(int cur, int visit) {
	if (visit == (1 << N) - 1) {
		if (cost[cur][0] != 0)return cost[cur][0];
		return INF;
	}
	if (dp[cur][visit])return dp[cur][visit];
	else {
		dp[cur][visit] = INF;
		for (int i = 0; i < N; i++) {
			if (!(visit&(1 << i)) && cost[cur][i]) {
				int a = cost[cur][i] + process(i, visit + (1 << i));
				dp[cur][visit] = min(dp[cur][visit], a);
			}
		}
		return dp[cur][visit];
	}
}
void solution() {
	printf("%d\n", process(0, 1));
}
int main() {
	freopen("02.in", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	solution();
	return 0;
}