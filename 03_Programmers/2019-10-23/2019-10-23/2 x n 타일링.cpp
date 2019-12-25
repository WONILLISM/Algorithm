#include<iostream>
#include<string>
#include<vector>

using namespace std;
int N;
int dp[60001];
int solution(int n) {
	if (n == 1)return dp[n] = 1;
	else if (n == 2)return dp[n] = 2;
	if (dp[n])return dp[n];
	else return dp[n] = solution(n - 1) + solution(n - 2);
}
int main() {
	cin >> N;
	solution(N);
	cout << dp[N] << "\n";
	return 0;
}