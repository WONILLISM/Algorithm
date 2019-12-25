#include<cstdio>

using namespace std;

int N, K;
int coin[101], dp[10001];
int solution() {
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	return dp[K];
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &coin[i]);
	printf("%d\n", solution());
	return 0;
}