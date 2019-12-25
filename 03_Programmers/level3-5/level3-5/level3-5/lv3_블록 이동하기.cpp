#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;
struct Pos {
	int y, x, d;
};

int N;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };//동 남 서 북
int err[4][2] = { {-1, 1}, {1, 1}, {1, -1}, {-1, -1} }; //시계면 nd, 반시계면 d
queue<Pos> q;
int visit[101][101][4];
vector<vector<int> > g;

bool Check(int y, int x, int d){
	if (y < 0 || x < 0 || y >= N || x >= N) return false;
	int ny = y + dir[d][0], nx = x + dir[d][1];
	if (ny < 0 || nx < 0 || ny >= N || nx >= N) return false;
	if (g[y][x] == 1 || g[ny][nx] == 1) return false;
	return true;
}

bool NoError(int y, int x){
	if (y < 0 || x < 0 || y >= N || x >= N) return false;
	if (g[y][x] == 1) return false;
	return true;
}

int solution(vector<vector<int>> board) {
	g = board, N = g.size();
	q.push({ 0, 0, 0 });
	visit[0][0][0] = 1;
	while (!q.empty()){
		Pos cur = q.front(); q.pop();
		int y = cur.y, x = cur.x, d = cur.d;
		if ((y == N - 1 && x == N - 1) || (y + dir[d][0] == N - 1 && x + dir[d][1] == N - 1))
			return visit[y][x][d] - 1;

		int ny, nx, nd, ey, ex;
		/*-------이동-------*/
		for (int i = 0; i < 4; i++){
			ny = y + dir[i][0], nx = x + dir[i][1], nd = d;
			if (Check(ny, nx, nd) && !visit[ny][nx][nd]){
				q.push({ ny, nx, nd });
				visit[ny][nx][nd] = visit[y][x][d] + 1;
			}
		}
		/*-------회전-------*/
		//시계
		ny = y, nx = x, nd = (d + 1) % 4;
		ey = y + err[nd][0], ex = x + err[nd][1];
		if (Check(ny, nx, nd) && !visit[ny][nx][nd] && NoError(ey, ex)){
			q.push({ ny, nx, nd });
			visit[ny][nx][nd] = visit[y][x][d] + 1;
		}

		//반시계
		ny = y, nx = x, nd = (d + 3) % 4;
		ey = y + err[d][0], ex = x + err[d][1];
		if (Check(ny, nx, nd) && !visit[ny][nx][nd] && NoError(ey, ex)){
			q.push({ ny, nx, nd });
			visit[ny][nx][nd] = visit[y][x][d] + 1;
		}

		//축 변경
		int ry = y + dir[d][0], rx = x + dir[d][1], rd = (d + 2) % 4;
		//시계
		ny = ry, nx = rx, nd = (rd + 1) % 4;
		ey = ry + err[nd][0], ex = rx + err[nd][1];
		if (Check(ny, nx, nd) && !visit[ny][nx][nd] && NoError(ey, ex)){
			q.push({ ny, nx, nd });
			visit[ny][nx][nd] = visit[y][x][d] + 1;
		}
		//반시계
		ny = ry, nx = rx, nd = (rd + 3) % 4;
		ey = ry + err[rd][0], ex = rx + err[rd][1];
		if (Check(ny, nx, nd) && !visit[ny][nx][nd] && NoError(ey, ex)){
			q.push({ ny, nx, nd });
			visit[ny][nx][nd] = visit[y][x][d] + 1;
		}
	}
	return -1;
}

int main() {
	vector<vector<int>> b = { 
		{0, 0, 0, 1, 1}, 
		{0, 0, 0, 1, 0}, 
		{0, 1, 0, 1, 1}, 
		{1, 1, 0, 0, 1}, 
		{0, 0, 0, 0, 0} };

	cout << solution(b) << endl;
	return 0;
}