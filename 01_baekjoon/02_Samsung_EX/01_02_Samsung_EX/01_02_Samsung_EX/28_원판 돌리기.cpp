#include<iostream>
#include<queue>

using namespace std;

const int MAX = 51;
int N, M, T, ans;
int Circle[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
//xi 원판 번호, di 회전방향, ki 회전시킬칸 수
int xi, di, ki;
/*
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
*/
typedef struct Pos {
	int x, y, value;
};

queue<Pos> q;

void rotate() {
	int Tmp[MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		if ((i+1)%xi == 0) {
			if (di == 1) {
				for (int j = 0; j < M; j++) 
					Tmp[j] = Circle[i][(j + ki) % M];
				for (int j = 0; j < M; j++)
					Circle[i][j] = Tmp[j];
			}
			else if (di == 0) {
				for (int j = 0; j < M; j++) 
					Tmp[(j + ki) % M] = Circle[i][j];
				for (int j = 0; j < M; j++)
					Circle[i][j] = Tmp[j];
			}
		}
	}
}
void process(int x, int y) {
	Pos cur = { x,y,Circle[y][x] };
	q.push(cur);
	for (int i = 0; i < 4; i++) {
		int nx = (cur.x + dx[i]) >= 0 ? ((cur.x + dx[i]) < M ? (cur.x + dx[i]) : 0) : M - 1;
		int ny = cur.y + dy[i];
		if (ny >= 0 && ny < N &&!visit[ny][nx]) {
			if (Circle[ny][nx] == cur.value) {
				q.push({ nx,ny, cur.value });
				visit[ny][nx] = 1;
				process(nx, ny);
				visit[ny][nx] = 0;
				Pos n = q.front();
				q.pop();

			}
		}
	}
}
void func(bool &chk) {
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Circle[i][j]) {
				visit[i][j] = 1;
				process(j, i);
				visit[i][j] = 0;
				if (q.size() == 1)q.pop();
				while (!q.empty()) {
					chk = true;
					Pos Q = q.front();
					q.pop();
					Circle[Q.y][Q.x] = 0;
				}
			}
		}
	}
	ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Circle[i][j]) {
				cnt++;
				ans += Circle[i][j];
			}
		}
	}
	if (!chk) {
		double d = ans /(double)cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Circle[i][j]) {
					if (Circle[i][j] < d) {
						Circle[i][j] += 1;
					}
					else if(Circle[i][j]>d){
						Circle[i][j] -= 1;
					}
				}
			}
		}
	}
}
void solution() {
	while (T--) {
		bool chk = false;
		cin >> xi >> di >> ki;
		rotate();
		func(chk);
	}
	cout << ans << endl;
}
int main() {
	freopen("28.in", "r", stdin);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Circle[i][j];
	solution();
	return 0;
}

//void process() {
//	int Tmp[MAX][MAX];
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			Tmp[i][j] = Circle[i][j];
//	
//	Pos cur = { 0,0};
//	visit[cur.y][cur.x] = 1;
//	q.push(cur);
//	while (!q.empty()) {
//		cur = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = (cur.x + dx[i]) >= 0 ? ((cur.x + dx[i]) < M ? (cur.x + dx[i]) : 0) : M - 1;
//			int ny = (cur.y + dy[i]) >= 0 ? ((cur.y + dy[i]) < N ? (cur.y + dy[i]) : 0) : N - 1;
//			if (!visit[ny][nx]) {
//				if (Circle[ny][nx] == Circle[cur.y][cur.x]) {
//					Tmp[cur.y][cur.x] = 0;
//					Tmp[ny][nx] = 0;
//					q.push({ nx,ny});
//					visit[ny][nx] = 1;
//				}
//				else {
//					q.push({ ny,nx });
//					visit[ny][nx] = 1;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			Circle[i][j] = Tmp[i][j];
//}