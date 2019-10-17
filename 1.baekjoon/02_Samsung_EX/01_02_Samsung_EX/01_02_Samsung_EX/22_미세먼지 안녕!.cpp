#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 50;
int R, C, T, ans;
int Map[MAX][MAX];
int Visit[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int d[2][4] = { { 0,1,2,3 }, { 2,1,0,3 } };
typedef struct Pos {
	int x, y;
	int dust;
};
vector<Pos> Clear;
queue<Pos> Q;

void Input() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == -1) Clear.push_back({ j, i });
		}
	}
}
//dir 0북, 1동, 2남, 3서
//dir 2남, 1동, 0북, 3서
void ActClear(int n, int x, int y, int dIdx) {
	if (Clear[n].x == x && Clear[n].y == y) {
		Map[y][x + 1] = 0;
		return;
	}
	Visit[y][x] = true;
	int nx, ny;
	ny = y + dy[d[n][dIdx]];
	nx = x + dx[d[n][dIdx]];
	if (n == 0 && (ny < 0 || nx < 0 || ny > Clear[n].y || nx > C-1)) {
		dIdx += 1;
		ny = y + dy[d[n][dIdx]];
		nx = x + dx[d[n][dIdx]];
	}
	if (n == 1 && (ny < Clear[n].y || nx < 0 || ny > R-1 || nx > C-1)) {
		dIdx += 1;
		ny = y + dy[d[n][dIdx]];
		nx = x + dx[d[n][dIdx]];
	}
	Map[y][x] = Map[ny][nx];
	ActClear(n, nx, ny, dIdx);

}
void Spread() {
	while (!Q.empty()) {
		int curx = Q.front().x;
		int cury = Q.front().y;
		int curdust = Q.front().dust;
		Q.pop();
		int sp = curdust / 5;
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx >= 0 && nx < C&&ny >= 0 && ny < R) {
				if (Map[ny][nx] > -1) {
					Map[ny][nx] += sp;
					Map[cury][curx] -= sp;
				}
			}
		}
	}
}
void Process() {
	for (int i = 0; i < T; i++) {
		while (!Q.empty())Q.pop();
		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				if (Map[a][b] > 0)Q.push({ b,a ,Map[a][b] });
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%3d", Map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		Spread();
		cout << "확산\n";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%3d", Map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		ActClear(1, Clear[1].x, Clear[1].y + 1, 0);
		ActClear(0, Clear[0].x, Clear[0].y - 1, 0);
		cout << "공기청정기\n";
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%3d", Map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (Map[i][j] > 0)
				ans += Map[i][j];
	cout << ans << "\n";

}
void Solution() {
	Input();
	Process();
}
int main() {
	freopen("22.in", "r", stdin);
	Solution();
	return 0;
}