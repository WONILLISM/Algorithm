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

int K, ans;
int gear[5][8];
int next_gear[5][8];
int check[5];

int d[2] = { -1, 1 };
queue<PII> q;		//idx, dir
void rotate(int num, int dir) {
	int tmp[8];
	if (dir == 1) {// 시계방향
		for (int i = 0; i < 8; i++)
			tmp[i] = gear[num][(i + 7) % 8];
	}
	else if (dir == -1) {
		for (int i = 0; i < 8; i++)
			tmp[i] = gear[num][(i + 1) % 8];
	}
	for (int i = 0; i < 8; i++)next_gear[num][i] = tmp[i];
}
void solution() {
	while (K--) {
		fill(&check[0], &check[5], 0);
		int idx, dir;		// 톱니바퀴 번호, 회전방향
		cin >> idx >> dir;
		
		q.push({ idx, dir });
		check[idx] = 1;
		while (!q.empty()) {
			PII cur = q.front(); q.pop();
			rotate(cur.first, cur.second);		// 현재 톱니바퀴 회전

			for (int i = 0; i < 2; i++) {
				int nidx = cur.first + d[i];
				int ndir = cur.second == 1 ? -1 : 1;
				if (nidx >= 1 && nidx <= 4 && !check[nidx]) {		// 톱니바퀴 번호 1~4 안에 들고 회전하지 않았다면
					if (i == 0&& gear[nidx][2] != gear[cur.first][6]) {	// 왼쪽과 비교할때
						check[nidx] = 1;
						q.push({ nidx, ndir });
					}
					else if (i == 1 && gear[nidx][6] != gear[cur.first][2]) {	// 오른쪽과 비교할때
						check[nidx] = 1;
						q.push({ nidx, ndir });
					}
				}
			}
		}

		// 동시에 회전
		for (int i = 1; i <= 4; i++) {
			if (check[i]) {
				for (int j = 0; j < 8; j++) {
					gear[i][j] = next_gear[i][j];
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
		if (gear[i+1][0])ans += 1 << i;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_4013.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ans = 0;
		cin >> K;
		for (int i = 1; i <= 4; i++)
			for (int j = 0; j < 8; j++)
				cin >> gear[i][j];
		
		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}