#include<iostream>
using namespace std;
const int MAX = 1000001;
int N;
int dp[MAX];
int Process(int n) {
	if (n <= 1) {
		dp[n] = 1;
		return dp[n] % 15746;
	}
	if (dp[n]) {
		return dp[n] % 15746;
	}
	else {
		dp[n] = (Process(n - 1) + Process(n - 2)) % 15746;
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