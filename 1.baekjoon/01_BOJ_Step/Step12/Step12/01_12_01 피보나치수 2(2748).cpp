#include<iostream>
using namespace std;
int N, T;
long long dp[91];
long long Process(int n) {
	if (n == 0) {
		dp[n] = 0;
		return dp[n];
	}
	else if (n == 1) {
		dp[n] = 1;
		return dp[n];
	}
	if (dp[n]) {
		return dp[n];
	}
	else {
		dp[n] = Process(n - 1) + Process(n - 2);
		return dp[n];
	}
}
void Solution() {
	cin >> N;
	Process(N);
	cout << dp[N] << "\n";
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}