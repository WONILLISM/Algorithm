#include<iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;
const int INF = 1234567;
/*---------- Àç±Í--------*/
ll dp[2001];
//f1
//f2 = 2
//f3 = f2 + f1 = 3
//f4 = f3 + f2
ll process(int n) {
	if (n == 1) return dp[n] = 1;
	if (n == 2) return dp[n] = 2;
	if (dp[n])return dp[n];
	else {
		dp[n] = process(n - 2) + process(n - 1);
		return dp[n] % INF;
	}
}
ll solution(int n) {
	ll answer = process(n);
	return answer;
}
/*----------¹Ýº¹¹®----------*/
//ll solution(int n) {
//	vector<ll> dp(n + 1, 0);
//	ll answer = 0;
//	dp[1] = 1;
//	dp[2] = 2;
//	for (int i = 3; i <= n; i++) {
//		dp[i] = dp[i - 2] + dp[i - 1];
//		dp[i] %= INF;
//	}
//	answer = dp[n];
//	return answer;
//}
int main() {
	cout << solution(3) << endl;
	return 0;
}