#include<cstdio>
const int MAX_N = 11;
const int MAX_Q = 11 * 11 * 2;
int N, M;
char Map[MAX_N][MAX_N];
bool Visit[MAX_N][MAX_N][MAX_N][MAX_N]; //두 구슬을 동시에 방문체크 하기 위함

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//두 구슬이 동시에 움직이므로 묶어서 관리
typedef struct Pos {
	int rx, ry;
	int bx, by;
	int step;
};
Pos Q[MAX_Q];
int f, r;
void push(int rx, int ry,int bx,int by,int s) {
	Q[r++] = { rx,ry,bx,by,s };
}
Pos pop() {
	return Q[f++];
}

void Input() {
	int rx, ry, bx, by;
	scanf("%d%d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &Map[i][j]);
			if (Map[i][j] == 'R')rx = j, ry = i;
			if (Map[i][j] == 'B')bx = j, by = i;
		}
		scanf("\n");
		Map[i][M] = '\0';
	}
	push(rx, ry, bx, by, 0);
	Visit[ry][rx][by][bx] = true;
}
void Move(int &x, int &y, int &c, int dy, int dx) {
	while (Map[y + dy][x + dx] != '#'&&Map[y][x] != 'O') {
		x += dx;
		y += dy;
		c +=1;
	}
}
void BFS() {
	Pos cur;
	while (f != r) {
		cur = pop();
		if (cur.step >= 10) break;
		for (int i = 0; i < 4; i++) {
			//다음 빨간 구슬, 파란구슬 좌표 변수 선언
			int nrx = cur.rx, nry = cur.ry;
			int nbx = cur.bx, nby = cur.by;
			//어떤 공이 더 기울이는 방향으로 앞에 있는지 확인하기 위한 변수
			int rc = 0, bc = 0;
			int nstep = cur.step + 1;
			//각 구슬을 벽이 막을때까지 이동시킨다.
			//c는 구슬의 이동한 칸을 카운트 한다.
			//더 많이 움직인 구슬이 더 뒤쪽에 있다.
			Move(nrx, nry, rc, dy[i], dx[i]);
			Move(nbx, nby, bc, dy[i], dx[i]);
			//파란구슬이 빠진경우는 실패이므로 제외한다.
			if (Map[nby][nbx] != 'O') {
				//빨간구슬이 빠지면 종료
				if (Map[nry][nrx] == 'O') {
					printf("%d\n", nstep);
					return;
				}
				//만약 두 구슬이 같은 위치에 있으면 같이 있을 수 없으므로
				//뒷쪽에 있던 구슬을 기울였던 방향과 반대로 한 칸 빼준다.
				if (nry == nby && nrx == nbx) {
					if (rc > bc)nry -= dy[i], nrx -= dx[i];
					else nby -= dy[i], nbx -= dx[i];
				}
				//움직인 후의 좌표가 방문하지 않은 곳이라면 푸시
				if (!Visit[nry][nrx][nby][nbx]) {
					Visit[nry][nrx][nby][nbx] = true;
					push(nrx,nry,nbx,nby,nstep);
				}
			}
		}
	}
	//10번 이상 움직였거나 공백 큐가 될때까지 성공하지 못했다면 실패이다.
	printf("-1\n");
}
int main() {
	freopen("01.in", "r", stdin);
	Input();
	BFS();

	return 0;
}