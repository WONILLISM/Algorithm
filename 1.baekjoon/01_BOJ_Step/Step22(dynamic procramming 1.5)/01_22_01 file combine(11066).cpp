#include<cstdio>
int MaxInt = 2 << 28;
int K;
int data[501];		//1~n까지 더한 값
int dp[501][501];	//i~j까지 더한 값 중 최솟값
void initData() {
	for (int i = 0; i < 501; i++) {
		data[i] = 0;
		for (int j = 0; j < 501; j++)
			dp[i][j] = 0;
	}
}
int minimum(int a, int b) { return a < b ? a : b; }
int abs(int x) { return x >= 0 ? x : -1 * x; }
int Process(int j, int ij) {
	if (j == ij)return 0;
	int min = MaxInt;
	for (int k = 0; k < abs(j - ij); k++) {
		min = minimum(min, dp[j][j + k] + dp[j + k + 1][ij] + data[ij] - data[j - 1]);
	}
	return min;
}
int main() {
	freopen("02.in", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &K);
		initData();
		for (int i = 1; i <= K; i++) {
			int a;
			scanf("%d", &a);
			data[i] = data[i - 1] + a;
		}
		for (int i = 0; i <= K; i++) {
			for (int j = 1; j <= K - i; j++) {
				dp[j][i + j] = Process(j, i + j);
			}
		}
		printf("%d\n", dp[1][K]);
	}

	return 0;
}