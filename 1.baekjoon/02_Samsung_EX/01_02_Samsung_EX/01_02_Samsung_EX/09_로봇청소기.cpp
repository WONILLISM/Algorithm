#include<iostream>

using namespace std;

const int MAX = 50;
int N, M, Answer;
int Map[MAX][MAX];
//D:ºÏ(0),µ¿(1),³²(2),¼­(3)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
typedef struct Pos {
	int x, y;
	int d;
};

Pos Q[MAX*MAX]; int f, r;
void push(int x, int y,int d) {
	Q[r++] = { x,y,d };
}
Pos pop() {
	return Q[f++];
}

void Input() {
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	push(c, r, d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}
void Process() {
	while (f != r) {
		Pos cur = pop();
		if (Map[cur.y][cur.x] == 0) {
			Map[cur.y][cur.x] = 2;
			Answer++;
		}

		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int nd = (cur.d + (3 - i)) % 4;
			int nx = cur.x + dx[nd];
			int ny = cur.y + dy[nd];
			if (ny >= 0 && nx >= 0 && ny < N&&nx < M) {
				if (!Map[ny][nx]) {
					push(nx, ny, nd);
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			//before
			int bx = cur.x - dx[cur.d];
			int by = cur.y - dy[cur.d];
			if ((by >= 0 && bx >= 0 && by < N&&bx < M) && Map[by][bx] != 1)
				push(bx, by, cur.d);
			else break;
		}
	}
}
void Solution() {
	Input();
	Process();
	cout << Answer << "\n";
}
int main() {
	freopen("09.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solution();
	return 0;
}