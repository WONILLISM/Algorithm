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
#define PIS pair<int,string>

using namespace std;
int T[500][500];
int dp[500][500];
int Max, N;
//n:높이 idx: 높이의 열
int process(int n, int idx) {
	if (idx < 0)return 0;
	if (n == 0)return dp[0][0] = T[0][0];

	if (dp[n][idx])return dp[n][idx];
	else {
		int a = process(n - 1, 0);
		for (int i = 0; i <= n; i++) {
			//int b = process(n - 1, i - 1);
			if (i == 0) {
				dp[n][i] = a + T[n][i];
			}
			else if (i > 0 && i < n) {
				int b = process(n - 1, i);
				int c = a > b ? a : b;
				dp[n][i] = c + T[n][i];
				a = b;
			}
			else if (i == n) {
				dp[n][i] = a + T[n][i];
			}
			Max = max(Max,dp[n][i]);
		}
		return dp[n][idx];
	}
}
void solution() {
	process(N-1, 0);
	cout << Max << endl;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> T[i][j];
		}
	}
	solution();
	return 0;
}