#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int answer;
int price[4];
int plan[13];
int dp[13];

int solution(int cur) {
	if (cur <= 0)return 0;
	if (dp[cur])return dp[cur];
	else {
		int m = solution(cur - 1);	// 1달 전 최솟값
		int m3 = solution(cur - 3);	// 3달 전 최솟값

		int day = m + plan[cur] * price[0];	//1일 이용권
		int month = m + price[1];			//1달 이용권
		int mon_3 = m3 + price[2];			//3달 이용권
		mon_3 = min(mon_3, m + price[2]);
		mon_3 = min(mon_3, solution(cur - 2) + price[2]);

		return dp[cur] = min(day, min(month, mon_3));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("swea_1952.in", "r", stdin);

	int tc; 
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < 4; i++)
			cin >> price[i];
		answer = price[3];
		for (int i = 1; i <= 12; i++)dp[i] = 0;
		for (int i = 1; i <= 12; i++)
			cin >> plan[i];

		answer = min(answer,solution(12));

		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}