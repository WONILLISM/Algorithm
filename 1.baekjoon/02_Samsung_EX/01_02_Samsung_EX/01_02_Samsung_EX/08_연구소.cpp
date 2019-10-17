#include <iostream>

using namespace std;
const int MAX = 8;

int N, M;
int Map[MAX][MAX];
int Tmp[MAX][MAX];
int Visit[MAX][MAX];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };

int Max;
int Safe;
typedef struct Pos {
	int x, y;
};
Pos Virus[10]; int v_Idx;

Pos Q[MAX*MAX]; int f, r;
void push(int x, int y) { Q[r++] = { x,y }; }
Pos pop() { return Q[f++]; }

void Input() {
	cin >> N >> M;
	Safe = M * N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] != 0) {
				Safe--;
				if (Map[i][j] == 2)	Virus[v_Idx++] = { j,i };
			}
		}
	}
}
void Bfs() {
	int z = Safe;
	int next[MAX][MAX];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			next[i][j] = Tmp[i][j];
			Visit[i][j] = false;
		}
	f = r = 0;
	for (int k = 0; k < v_Idx; k++) {
		push(Virus[k].x, Virus[k].y);
		Visit[Virus[k].y][Virus[k].x] = true;
	}
	
	while (f != r) {
		Pos cur = pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M&&ny < N&&next[ny][nx]==0) {
				if (!Visit[ny][nx]) {
					next[ny][nx] = 2;
					Visit[ny][nx] = true;
					z--;
					push(nx, ny);
				}
			}
		}
	}
	if (Max < z)Max = z;
}
void makeWall(int cnt){
	if (cnt == 3)	{
		Bfs();
		return;
	}
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j <M; j++){
			if (Tmp[i][j] == 0){
				Tmp[i][j] = 1;
				Safe--;
				makeWall(cnt + 1);
				Tmp[i][j] = 0;
				Safe++;
			}
		}
	}
}
void Solution() {
	Input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						Tmp[i][j] = Map[i][j];
					}
				}
				Tmp[i][j] = 1;
				Safe--;
				makeWall(1);
				Tmp[i][j] = 0;
				Safe++;
			}
		}
	}
	cout << Max << endl;
}
int main() {
	freopen("08.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solution();
	return 0;
}