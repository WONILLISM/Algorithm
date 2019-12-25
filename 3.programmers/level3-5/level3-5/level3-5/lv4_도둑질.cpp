#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> M;
int dp[1000000];

int process(int n) {
	if (dp[n])return dp[n];
	else {
		int a = process(n - 2) + M[n];
		int b = process(n - 1);
		dp[n] = a > b ? a : b;
		return dp[n];
	}
}
int solution(vector<int> money) {
	M = money;
	int n = money.size();
	dp[0] = money[0];
	dp[1] = money[0];
	int res1 = process(n - 2);
	dp[0] = 0;
	dp[1] = money[1];
	int res2 = process(n - 1);
	return res1 > res2 ? res1 : res2;
}
//int process(int n) {
//	dp[0] = M[0];
//	dp[1] = M[0];
//	for (int i = 2; i < n-1; i++) {
//		int a = dp[i - 2] + M[i];
//		int b = dp[i - 1];
//		dp[i] = a >= b ? a : b;
//	}
//	int res1 = dp[n - 2];
//	dp[0] = 0;
//	dp[1] = M[1];
//	for (int i = 2; i < n; i++) {
//		int a = dp[i - 2] + M[i];
//		int b = dp[i - 1];
//		dp[i] = a >= b ? a : b;
//	}
//	int res2 = dp[n - 1];
//	return res1 >= res2 ? res1 : res2;
//}
//int solution(vector<int> money) {
//	M = money;
//	int N = money.size();
//	return process(N);
//}
int main() {
	vector<int> money = { 1,2,3,4,5,6 };
	cout << solution(money) << endl;
}