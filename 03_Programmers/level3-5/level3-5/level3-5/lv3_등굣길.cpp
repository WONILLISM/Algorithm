#include<iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 101;
int dp[MAX][MAX];

void process(int m, int n) {

	
	/*if (dp[cury][curx] == -1)return 0;
	if (curx < 1 || cury < 1)return 0;
	if (curx == 1 && cury == 1) return dp[cury][curx] = 1;
	if (dp[cury][curx])return dp[cury][curx];
	else {
		dp[cury][curx] = process(curx, cury - 1) + process(curx - 1, cury);
		return dp[cury][curx];
	}*/
}
int solution(int m, int n, vector<vector<int>> puddles) {
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
	return dp[n][m];
}
int main() {
	vector<vector<int>> puddles = { {2,2} };
	cout << solution(4, 3, puddles) << endl;

}