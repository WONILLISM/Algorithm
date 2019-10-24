#include<iostream>

using namespace std;
int T, N;
long long dp[101];
long long Process(int n) {
	if (n == 0) {
		dp[n] = 0;
		return dp[n];
	}
	else if (n <= 3) {
		dp[n] = 1;
		return dp[n];
	}
	else if (n <= 5) {
		dp[n] = 2;
		return dp[n];
	}
	if (dp[n]) {
		return dp[n];
	}
	else {
		dp[n] = Process(n - 1) + Process(n - 5);
		return dp[n];
	}
}
void Solution() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < 101; i++)dp[i] = 0;
		Process(N);
		cout << dp[N] << "\n";
	}
}
int main() {
	Solution();
	return 0;
}