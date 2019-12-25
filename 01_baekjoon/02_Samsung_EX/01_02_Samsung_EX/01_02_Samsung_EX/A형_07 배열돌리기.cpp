#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 51;
int N, M, K, Ans = 1 << 30;
int A[MAX][MAX];
int tmp[MAX][MAX];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
typedef struct rcs {
	int idx;
	int r, c, s;
};
vector<rcs> cmd;
bool compare(rcs a, rcs b) {
	return a.idx < b.idx;
}
int chkCmd[6];
//좌상단 (r-s, c-s)
//우하단 (r+s, c+s)
void rotation(vector<rcs> c) {
	queue<pair<pair<int,int>,int>> q;
	for (int i = 0; i < c.size(); i++) {
		int visit[MAX][MAX] = { 0, };
		rcs cur = c[i];
		int edgeX[2] = { cur.c - cur.s, cur.c + cur.s };
		int edgeY[2] = { cur.r - cur.s, cur.r + cur.s };
		int curx = edgeX[0], cury = edgeY[0];
		q.push({ { curx,cury },tmp[cury][curx] });
		visit[cury][curx] = 1;
		int dir = 0;
		while (1) {
			curx = q.front().first.first, cury = q.front().first.second;
			int cvalue = q.front().second;
			q.pop();
			int nx = curx + dx[dir], ny = cury + dy[dir];
			if (nx >= edgeX[0] && nx <= edgeX[1] && ny >= edgeY[0] && ny <= edgeY[1]) {
				q.push({ { nx,ny }, tmp[ny][nx] });
				visit[ny][nx] = 1;
				tmp[ny][nx] = cvalue;
			}
			else {
				dir += 1;
				if (dir == 4) {
					edgeX[0] += 1;
					edgeX[1] -= 1;
					edgeY[0] += 1;
					edgeY[1] -= 1;
					if (edgeX[0] == edgeX[1] && edgeY[0] == edgeY[1])break;
					if (edgeX[0] > edgeX[1] || edgeY[0] > edgeY[1])break;
					if (visit[edgeY[0]][edgeX[0]] || visit[edgeY[1]][edgeX[1]])break;
					dir = 0;
					curx = edgeX[0], cury = edgeY[0];
					q.push({ { curx,cury }, tmp[cury][curx] });
					visit[cury][curx] = 1;
				}
				else {
					nx = curx + dx[dir], ny = cury + dy[dir];
					q.push({ {nx,ny},tmp[ny][nx] });
					visit[ny][nx] = 1;
					tmp[ny][nx] = cvalue;
				}
			}
		}
	}
}
void process(int idx, int cnt) {
	if (cnt == cmd.size()) {
		vector<rcs> c;
		for (int i = 0; i < cmd.size(); i++) {
			if (chkCmd[i]) {
				cout << chkCmd[i] << " ";
				c.push_back({ chkCmd[i],cmd[i].r,cmd[i].c,cmd[i].s });
			}
		}
		cout << endl;
		sort(c.begin(), c.end(), compare);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				tmp[i][j] = A[i][j];
		rotation(c);
		int Sum = 0;
		for (int i = 1; i <= N; i++) {
			Sum = 0;
			for (int j = 1; j <= M; j++) {
				Sum += tmp[i][j];
			}
			if (Ans > Sum)Ans = Sum;
		}
	}
	for (int i = 0; i < cmd.size(); i++) {
		if (!chkCmd[i]) {
			chkCmd[i] = cnt + 1;
			process(i, cnt + 1);
			chkCmd[i] = 0;
		}
	}
}
void solution() {
	process(0, 0);
	cout << Ans << endl;
}
int main() {
	freopen("a_07.in", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	int r, c, s;
	while (K--) {
		cin >> r >> c >> s;
		cmd.push_back({ 0,r,c,s });
	}
	solution();
	return 0;
}