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
const int MAX = 501;
const int MOD = 20170805;

int dp[2][MAX][MAX];	// 왼쪽-> 오른쪽 dp, 위쪽->아래쪽 dp
int solution(int m, int n, vector<vector<int>> city_map) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == 0) && (j == 0)) {		//출발점
				dp[0][i][j] = 1;
				dp[1][i][j] = 1;
			}
			else if (city_map[i][j] == 0) {		// 이전 좌표 값들 체크 
				dp[0][i][j] = (dp[0][i][j - 1] + dp[1][i - 1][j]) % MOD;	// 왼->오 + 위->아래 % MOD
				dp[1][i][j] = (dp[0][i][j - 1] + dp[1][i - 1][j]) % MOD;
			}
			else if (city_map[i][j] == 1) {
				dp[0][i][j] = 0;
				dp[1][i][j] = 0;
			}
			else if (city_map[i][j] == 2) {
				dp[0][i][j] = dp[0][i][j - 1];
				dp[1][i][j] = dp[1][i - 1][j];
			}
		}
	}
	return dp[0][m - 1][n - 1];
}
int main() {
	//cout << solution(3,6,{{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}});
	cout << solution(3, 3, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} });
	return 0;
}