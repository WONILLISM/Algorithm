#include<iostream>

using namespace std;

const int MAX = 100;
int N, K, M; //N: 맵의 크기,  K: 사과의 개수, M: 뱀의 방향 변환 횟수

//우 좌 하 상
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int L[4] = { 3,2,0,1 }, D[4] = { 2,3,1,0 };
int dir = 0;//뱀의 현재 방향

int answer;
int Map[MAX][MAX];

typedef struct DirInfo {
	int time;
	char direct;
}Dir;
Dir d[MAX + 1];
int dIdx;

typedef struct Pos {
	int x, y;
};

Pos Q[MAX*MAX]; int f, r;
void push(int x, int y) {
	Q[r++] = { x,y};
}
Pos pop() {
	return Q[f++];
}
void Input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		Map[a - 1][b - 1] = 2;	//사과를 2라고 표시
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> d[i].time >> d[i].direct;
	}

}
void Process() {
	Pos cur = { 0,0 };
	Pos next;

	Map[cur.y][cur.x] = 1;
	push(cur.x, cur.y);
	while (1) {
		cur.x += dx[dir];
		cur.y += dy[dir];
		answer++;
		if (cur.y < 0 || cur.x < 0 || cur.x >= N || cur.y >= N||Map[cur.y][cur.x]==1) {
			cout << answer << endl;
			return;
		}
		if (Map[cur.y][cur.x] == 0) {
			next = pop();
			Map[next.y][next.x] = 0;
		}
		Map[cur.y][cur.x] = 1;
		push(cur.x, cur.y);

		if (answer == d[dIdx].time) {
			if (d[dIdx].direct == 'L') dir = L[dir];
			else dir = D[dir];
			dIdx++;
		}
	}
}
void solution() {
	Input();
	Process();
}
int main(){
	freopen("03.in", "r", stdin);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solution();
	return 0;
}