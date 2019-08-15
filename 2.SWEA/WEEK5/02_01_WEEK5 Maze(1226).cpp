#include<cstdio>

typedef struct Pos{
	int x, y;
	int step;
};
char Map[16][17];
int c_Step[16][16];
bool Visit[16][16];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
Pos Q[256];
int f, r;
void push(int y, int x, int step) {
	Q[r].y = y;
	Q[r].x = x;
	Q[r].step = step;
	r++;
}
Pos pop(){
	return Q[f++];
}
void Init() {
	f = r = 0;
	for (int i = 0; i < 256; i++) Q[i] = { 0,0 };
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			Visit[i][j] = false;
			Map[i][j] = '\0';
		}
	}
	scanf("%*d");
	for (int i = 0; i < 16; i++)
		scanf("%s", Map[i]);
}
int BFS(int y, int x) {
	Pos cur = { x,y };
	cur.step = 1;
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
			if (nx >= 0 && nx < 16 && ny >= 0 && ny < 16) {
				if (!Visit[ny][nx] && (Map[ny][nx] == '0'||Map[ny][nx]  =='3')) {
					Visit[ny][nx] = true;
					c_Step[ny][nx] = cur.step + 1;
					push(ny, nx, cur.step + 1);
				}
			}
		}
	}
	if (Map[cur.y][cur.x] == '3')return 1;
	else return 0;
}
int main() {
	freopen("WEEK5(1226).in.txt", "r", stdin);
	int ans;
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		ans = BFS(1, 1);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}