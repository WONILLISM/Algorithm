#include<cstdio>

typedef struct Pos {
	int x, y;
	int step;
};
char Map[100][101];
int c_Step[100][100];
bool Visit[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
Pos Q[10201];
int f, r;
void push(int y, int x, int step) {
	Q[r].y = y;
	Q[r].x = x;
	Q[r].step = step;
	r++;
}
Pos pop() {
	return Q[f++];
}
void Init() {
	f = r = 0;
	for (int i = 0; i < 10201; i++) Q[i] = { 0,0,0 };
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 101; j++) {
			Visit[i][j] = false;
			Map[i][j] = '\0';
		}
	}
	scanf("%*d\n");
	for (int i = 0; i < 100; i++)
		scanf("%s", Map[i]);
}
int BFS(int y, int x) {
	Pos cur = { x,y ,1 };
	push(y, x, cur.step);
	Visit[y][x] = true;
	c_Step[y][x] = cur.step;
	while (f != r) {
		cur = pop();
		int nx, ny;
		if (Map[cur.y][cur.x] == '3')return 1;
		for (int i = 0; i < 4; i++) {
			ny = cur.y + dy[i];
			nx = cur.x + dx[i];
			if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100) {
				if (!Visit[ny][nx] && (Map[ny][nx] == '0' || Map[ny][nx] == '3')) {
					Visit[ny][nx] = true;
					c_Step[ny][nx] = cur.step + 1;
					push(ny, nx, cur.step + 1);
				}
			}
		}
	}
	return 0;
}
int main() {
	freopen("WEEK5(1227).in.txt", "r", stdin);
	int ans = 0;
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		ans = BFS(1, 1);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}