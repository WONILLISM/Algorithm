#include<cstdio>
const int MAX_N = 11;
const int MAX_Q = 11 * 11 * 2;
int N, M;
char Map[MAX_N][MAX_N];
bool Visit[MAX_N][MAX_N][MAX_N][MAX_N]; //�� ������ ���ÿ� �湮üũ �ϱ� ����

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//�� ������ ���ÿ� �����̹Ƿ� ��� ����
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
			//���� ���� ����, �Ķ����� ��ǥ ���� ����
			int nrx = cur.rx, nry = cur.ry;
			int nbx = cur.bx, nby = cur.by;
			//� ���� �� ����̴� �������� �տ� �ִ��� Ȯ���ϱ� ���� ����
			int rc = 0, bc = 0;
			int nstep = cur.step + 1;
			//�� ������ ���� ���������� �̵���Ų��.
			//c�� ������ �̵��� ĭ�� ī��Ʈ �Ѵ�.
			//�� ���� ������ ������ �� ���ʿ� �ִ�.
			Move(nrx, nry, rc, dy[i], dx[i]);
			Move(nbx, nby, bc, dy[i], dx[i]);
			//�Ķ������� �������� �����̹Ƿ� �����Ѵ�.
			if (Map[nby][nbx] != 'O') {
				//���������� ������ ����
				if (Map[nry][nrx] == 'O') {
					printf("%d\n", nstep);
					return;
				}
				//���� �� ������ ���� ��ġ�� ������ ���� ���� �� �����Ƿ�
				//���ʿ� �ִ� ������ ��￴�� ����� �ݴ�� �� ĭ ���ش�.
				if (nry == nby && nrx == nbx) {
					if (rc > bc)nry -= dy[i], nrx -= dx[i];
					else nby -= dy[i], nbx -= dx[i];
				}
				//������ ���� ��ǥ�� �湮���� ���� ���̶�� Ǫ��
				if (!Visit[nry][nrx][nby][nbx]) {
					Visit[nry][nrx][nby][nbx] = true;
					push(nrx,nry,nbx,nby,nstep);
				}
			}
		}
	}
	//10�� �̻� �������ų� ���� ť�� �ɶ����� �������� ���ߴٸ� �����̴�.
	printf("-1\n");
}
int main() {
	freopen("01.in", "r", stdin);
	Input();
	BFS();

	return 0;
}