#include<iostream>

using namespace std;
const int MAX = 20;
const int MAX_K = 1000;
int N, M, K;
int Map[MAX][MAX];

int Cmd[MAX_K];
int Dice[6];

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
int dir[4][6] =
{
	{2, 1, 5, 0, 4, 3},
	{3, 1, 0, 5, 4, 2},
	{1, 5, 2, 3, 0, 4},
	{4, 0, 2, 3, 5, 1},
};
typedef struct Pos {
	int x, y;
};
Pos Q[1000]; int f, r;
void push(int x, int y) { Q[r++] = { x,y }; }
Pos pop() { return Q[f++]; }

void Init() {
	int x, y;
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
		cin >> Cmd[i];
	push(x, y);
}
void Command(int c) {
	int tmp_Dice[6];
	int idx = Cmd[c];
	for (int i = 0; i < 6; i++) tmp_Dice[i] = Dice[dir[idx - 1][i]];
	for (int i = 0; i < 6; i++)Dice[i] = tmp_Dice[i];
}
void Process() {
	for (int i = 0; i < K; i++) {
		Pos cur = pop();
		int nx, ny;
		int c = Cmd[i] - 1;
		nx = cur.x + dx[c];
		ny = cur.y + dy[c];
		if (ny >= 0 && nx >= 0 && ny < N&&nx < M) {
			Command(i);
			if (Map[ny][nx] == 0) {
				Map[ny][nx] = Dice[0];
			}
			else {
				Dice[0] = Map[ny][nx];
				Map[ny][nx] = 0;
			}
			cout << Dice[5] << endl;
			push(nx, ny);
		}
		else push(cur.x, cur.y);
	}
}
void Solution() {
	Init();
	Process();
}
int main() {
	freopen("05.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}