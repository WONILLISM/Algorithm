#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 501;
int dp[MAX][MAX];
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); ++i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				int a = dp[i - 1][j - 1];
				int b = dp[i - 1][j];
				dp[i][j] = (a > b ? a : b) + triangle[i][j];
			}
			if ((i == triangle.size() - 1) && (answer < dp[i][j])) {
				answer = dp[i][j];
			}
		}
	}
	return answer;
}
int main() {
	vector<vector<int>> t = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };
	cout << solution(t) << endl;
}