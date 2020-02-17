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
using namespace std;
const int MAX = 101;

int dp[MAX][MAX];
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	dp[1][1] = 1;
	for (int i = 0; i < puddles.size(); i++)
		dp[puddles[i][1]][puddles[i][0]] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!dp[i][j]) {
				if (dp[i - 1][j] == -1)dp[i][j] = dp[i][j - 1];
				else if (dp[i][j - 1] == -1)dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= 1000000007;
			}
		}
	}
	if (dp[n][m] == -1)return 0;
	answer = dp[n][m];
	return answer;
}

int main() {
	cout << solution(4, 3, { {2,2} }) << endl;
	return 0;
}