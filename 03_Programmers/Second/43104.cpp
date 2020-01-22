#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 81;
int dp[MAX];

ll solution(int n) {
	if (n == 1)return dp[n] = 4;
	if (n == 2)return dp[n] = 6;

	if (dp[n])return dp[n];
	else {
		dp[n] = solution(n - 1) + solution(n - 2);
		return dp[n];
	}
}
int main() {
	cout << solution(5) << endl;
	return 0;
}