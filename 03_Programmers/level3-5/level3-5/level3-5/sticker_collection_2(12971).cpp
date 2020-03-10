#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define PIS pair<int,string>

using namespace std;
int dp[100001];

int solution(vector<int> sticker){
	int answer = 0;
	int n = sticker.size();

	if (n == 1)return sticker[0];
	else if (n == 2)return max(sticker[0], sticker[1]);
	else {
		// 첫번째 스티커 사용
		dp[0] = sticker[0];
		dp[1] = sticker[0];

		for (int i = 2; i < n - 1; i++)
			dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
		answer = dp[n - 2];

		// 첫번째 스티커 사용 x
		dp[0] = 0;
		dp[1] = sticker[1];
		for (int i = 2; i < n; i++)
			dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
		answer = max(answer, dp[n - 1]);
		return answer;
	}
}
int main() {
	cout << solution({ 14, 6, 5, 11, 3, 9, 2, 10 }) << endl;
	return 0;
}