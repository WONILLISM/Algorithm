#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

int D, W, K, ans;
int Map[13][20];
int Tmp[13][20];
int chk[13]; // 약품 투여 여부

// 성능 검사
bool check() {
	int cnt;
	for (int i = 0; i < W; i++) {
		cnt = 1;
		for (int j = 1; j < D; j++) {
			if (cnt >= K)break;
			if (Tmp[j - 1][i] == Tmp[j][i])cnt++;
			else cnt = 1;
		}
		if (cnt < K)return false;
	}
	return true;
}
// dfs - 약품 종류, 깊이, 약품 투여 횟수
void process(int depth, int cnt) {
	if (cnt>=ans)return;
	if (depth > D) {
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				if (chk[i] != -1) {
					Tmp[i][j] = chk[i];
				}
				else Tmp[i][j] = Map[i][j];
			}
		}

		if (check()) 
			ans = min(ans, cnt);
		return;
	}
	chk[depth] = -1;
	process(depth + 1, cnt);//투여 안함
	chk[depth] = 0;
	process(depth + 1, cnt + 1);//a 투여
	chk[depth] = 1;
	process(depth + 1, cnt + 1);//b 투여
}
void solution() {
	process(0, 0);
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_2112.in", "r", stdin);
	int t; cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> D >> W >> K;
		/*----- Init ----*/
		ans = 13;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> Map[i][j];
			}
		}
		solution();
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}