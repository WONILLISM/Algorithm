#include<iostream>
using namespace std;
const int MAX = 500;

int N, M, Max;
int Map[MAX][MAX];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
typedef struct Pos {
	int x, y;
};
Pos Tetromino[19][4] =
{
	{{0,0},{0,1},{1,0},{1,1\}\},	//け
	{{0,0},{1,0},{2,0},{3,0\}\},	//ぱ び
	{{0,0},{0,1},{0,2},{0,3\}\},
	{{0,1},{1,1},{2,1},{1,0\}\},	//で ぬ っ た
	{{0,0},{1,0},{2,0},{1,1\}\},
	{{0,1},{1,0},{1,1},{1,2\}\},
	{{0,0},{0,1},{0,2},{1,1\}\},
	{{0,0},{1,0},{1,1},{2,1\}\},	//z
	{{1,0},{1,1},{0,1},{0,2\}\},
	{{0,1},{1,1},{1,0},{2,0\}\},
	{{0,0},{0,1},{1,1},{1,2\}\},
	{{0,0},{1,0},{2,0},{2,1\}\},	//ぁ い
	{{0,0},{0,1},{0,2},{1,0\}\},
	{{0,0},{0,1},{1,1},{2,1\}\},
	{{0,2},{1,2},{1,1},{1,0\}\},
	{{0,0},{1,0},{2,0},{0,1\}\},
	{{0,0},{0,1},{0,2},{1,2\}\},
	{{0,1},{1,1},{2,1},{2,0\}\},
	{{0,0},{1,0},{1,1},{1,2\}\}
};
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
}
void Process(int x, int y) {
	Pos cur = { x,y };
	for (int i = 0; i < 19; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int nx = cur.x + Tetromino[i][j].x;
			int ny = cur.y + Tetromino[i][j].y;
			if (nx >= 0 && ny >= 0 && nx < M&&ny < N) {
				sum += Map[ny][nx];
			}
			else break;
			if (Max < sum)Max = sum;
		}
	}
}
void Solution() {
	Input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Process(j, i);
		}
	}
	cout << Max << endl;
}
int main() {
	freopen("06.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	Solution();
	return 0;
}
