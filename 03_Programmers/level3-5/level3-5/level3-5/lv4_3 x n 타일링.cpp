#include<iostream>
using namespace std;
const int MOD = 1000000007;
long long dp[5001];
long long process(int n) {
	if (n == 0) return 1;
	if (n == 1)	return 0;
	if (n == 2) return 3;
	if (dp[n]) return dp[n];
	else {
		dp[n] = 3 * process(n - 2);
		for (int i = 4; i <= n; i += 2) {
			dp[n] += 2 * process(n - i);
		}
		dp[n] %= MOD;
		return dp[n];
	}
}
int solution(int n) {
	int answer = 0;
	answer = process(n);
	return answer;
}
int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}