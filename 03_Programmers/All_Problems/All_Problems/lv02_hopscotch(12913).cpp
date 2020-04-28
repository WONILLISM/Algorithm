#include <iostream>
#include<algorithm>
#include <vector>
#define endl '\n'
using namespace std;
int dp[100000][4];
int n;

int solution(vector<vector<int>> land) {
	int answer = 0;
	for (int i = 0; i < 4; i++)
		dp[0][i] = land[0][i];

	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {		
			for (int k = 0; k < 4; k++) {	
				if (k != j)
					dp[i][j] = max(dp[i][j], land[i][j] + dp[i - 1][k]);
			}
		}
	}
	for (int i = 0; i < 4; i++)
		answer = max(answer, dp[land.size() - 1][i]);
	return answer;
}
int main() {
	cout << solution({ {1, 2, 3, 5}, { 5, 6, 7, 8 }, { 4, 3, 2, 1 } }) << endl;
	return 0;
}
