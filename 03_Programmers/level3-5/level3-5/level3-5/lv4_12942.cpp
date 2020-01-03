#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;
const int MAX_INT = 1 << 30;
int dp[201][201];
int solution(vector<vector<int>> matrix_sizes){
	int answer = 0, s = matrix_sizes.size();
	for (int a = s - 1; a >= 0; --a) {
		for (int c = a + 1; c < s; ++c) {
			dp[a][c] = MAX_INT;
			for (int b = a; b < c; ++b)
				dp[a][c] = min(dp[a][c], dp[a][b] + dp[b + 1][c] + matrix_sizes[a][0] * matrix_sizes[b][1] * matrix_sizes[c][1]);
		}
	}
	return dp[0][s - 1];
}
int main() {
	cout << solution({ {5,3},{3,10},{10,6},{6,4} }) << endl;
	return 0;
}