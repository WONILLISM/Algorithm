#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
using namespace std;

const int MAX = 21;
int Map[MAX][MAX];
int N, X, ans;

void process(int i, bool dir) {
	int cnt = 1;	// 현재 좌표 count
	for (int j = 0; j < N - 1; j++) {
		// 다음 좌표 높이와 현재 좌표 높이의 차이
		int d = dir ? Map[i][j + 1] - Map[i][j] : Map[j + 1][i] - Map[j][i];
		if (d == 0)cnt++;	// 경사로를 세울 수 있다면 count 증가
		else if (d == 1 && cnt >= X)cnt = 1;	// 경사로 길이를 초과하여 지엇다면 cnt=1로 초기화
		else if (d == -1 && cnt >= 0)cnt = -X + 1;		
		// 아래로 내려가는 상황이면 count를 음수에서부터 0으로 X만큼 세어주기 위해 cnt = -X + 1;
		else return;
	}
	if (cnt >= 0) ans++;
}
void solution() {
	for (int i = 0; i < N; i++) {
		process(i, true);	// ture : 가로
		process(i, false);	// false : 세로
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_4014.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ans = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> Map[i][j];

		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}