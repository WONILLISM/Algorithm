#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 5001;
const int MOD = 1000000007;
int dp[MAX];

int solution(int n) {
	if (n == 0)return dp[n] = 1;
	if (n == 2)return dp[n] = 3;

	if (dp[n])return dp[n];
	else {
		dp[n] = 3 * solution(n - 2);
		for (int i = n; i >= 4; i -= 2)
			dp[n] += 2 * solution(n - i);
		return dp[n] %= MOD;
	}
}
int main() {
	cout << solution(6) << endl;
	return 0;
}