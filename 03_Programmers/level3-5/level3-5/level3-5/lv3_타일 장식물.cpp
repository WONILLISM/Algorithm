#include<iostream>

using namespace std;

long long dp[81];
long long solution(int n) {
	if (n == 1)return dp[n] = 4;
	else if (n == 2)return dp[n] = 6;
	if (dp[n]) return dp[n];
	else {
		dp[n] = solution(n - 1) + solution(n - 2);
		return dp[n];
	}
}
int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}