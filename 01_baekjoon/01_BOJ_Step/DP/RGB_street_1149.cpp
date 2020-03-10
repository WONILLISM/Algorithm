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

int N;
int dp[3];

void solution() {
	int answer = 0;
	int R, G, B, cur[3];	// 누적 값, 현재 값
	cin >> R >> G >> B;		// 초기 값
	for (int i = 0; i < N - 1; i++) {
		cin >> cur[0] >> cur[1] >> cur[2];

		dp[0] = R, dp[1] = G, dp[2] = B;

		R = cur[0] + min(dp[1], dp[2]);
		G = cur[1] + min(dp[0], dp[2]);
		B = cur[2] + min(dp[0], dp[1]);
	}
	answer = min(R, min(G, B));
	cout << answer << endl;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	solution();
}