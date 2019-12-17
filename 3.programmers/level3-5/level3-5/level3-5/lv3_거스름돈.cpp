#include<iostream>
#include <string>
#include <vector>

using namespace std;

int dp[100001];
int solution(int n, vector<int> money) {
	dp[0] = 1;
	for (int i = 0; i < money.size(); i++) {
		int coin = money[i];
		for (int j = coin; j <= n; j++) {
			dp[j] += dp[j - coin];
		}
	}
	return dp[n];
}

int main() {
	cout << solution(5, { 1,2,5 }) << endl;
	return 0;
}