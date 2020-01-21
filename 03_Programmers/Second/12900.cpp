#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MOD = 1000000007;
int dp[60001];

int process(int n) {
	if (n == 1)return dp[1] = 1;
	if (n == 2) return dp[2] = 2;
	if (dp[n])return dp[n];
	else {
		dp[n] = (process(n - 1) + process(n - 2)) % MOD;
		return dp[n];
	}
}
int solution(int n) {
	int answer = 0;
	process(n);
	answer = dp[n];
	return answer;
}
int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}
