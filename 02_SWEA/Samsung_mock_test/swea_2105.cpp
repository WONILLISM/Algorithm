#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

const int MAX = 20;
int N, ans;
int Map[MAX][MAX];
bool chk[101];
int sx, sy;//시작점
int dx[] = { 1,-1,-1,1 };
int dy[] = { 1,1,-1,-1 };

//dfs
void process(int x, int y, int dir,int step) { //좌표 x,y , 방향 
	if (dir == 3) {
		if (x == sx - 1 && y == sy + 1) {
			ans = max(ans, step);
			return;
		}
	}
	int nx = x + dx[dir], ny = y + dy[dir];
	if (nx >= 0 && nx < N&& ny >= 0 && ny < N) {
		if (!chk[Map[ny][nx]]) {
			chk[Map[ny][nx]] = true;
			process(nx, ny, dir, step + 1); //회전 안함
			process(nx, ny, dir + 1, step + 1); //회전 함
			chk[Map[ny][nx]] = false;
		}
	}
}
void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sx = j, sy = i;
			chk[Map[i][j]] = true;
			process(j, i, 0, 1);
			chk[Map[i][j]] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_2105.in", "r", stdin);
	int t; cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		/*----- Init ----*/
		ans = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Map[i][j] = 0;
		for (int i = 0; i < 101; i++)chk[i] = false;
		/*----- Init ----*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
			}
		}
		solution();
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}
