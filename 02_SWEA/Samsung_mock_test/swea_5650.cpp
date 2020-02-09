#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

#define endl "\n"
#define ll long long
#define PII pair<int,int>

using namespace std;

const int MAX = 101;
int Map[MAX][MAX];
int visit[MAX][MAX];
int N, ans;
int sx, sy;//시작점
bool gameover;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int convDir[5][4] = {	//블럭 모양에 따른 방향전환
	{0,0,0,0},
	{2,0,3,1},
	{2,3,1,0},
	{1,3,0,2},
	{3,2,0,1}
};

vector<vector<PII>> wormhole;//웜홀 쌍의 위치(y,x)
struct Pinball {
	int y, x, dir, score;
};
//블럭 ㅇ\(1), ㅇ/(2), \ㅇ(3), /ㅇ(4), ㅁ(5)
//웜홀 6 ~ 10, 블랙홀 -1
//웜홀은 반드시 쌍으로 이루어져있으며 반대쪽으로 나옴
//핀볼이 출발위치로 돌아오거나 블랙홀을 만나면 게임 종료
//게임에서 얻을 수 있는 최대 점수(점수는 벽이나 블록에 부딪힌 횟수)

bool isRange(int y, int x) { return x > 0 && x <= N && y > 0 && y <= N; }
void process(int y, int x, int dir, int cnt) {
	if (gameover)return;
	int ny = y + dy[dir], nx = x + dx[dir];
	
	int num = Map[ny][nx]; // 웜홀 번호 ,블럭 번호, 빈 공간, 블랙홀
	if (isRange(ny, nx)) {
		if (num == -1 || (ny == sy && nx == sx)) {	//종료 조건 처리
			ans = max(cnt, ans);
			gameover = true;
			return;
		}
		if (num >= 6 && num <= 10) {		// 웜홀 조건 처리
			
			int wy, wx; //다음 웜홀 좌표
			if (ny == wormhole[num - 6][0].first && nx == wormhole[num - 6][0].second)
				wy = wormhole[num - 6][1].first, wx = wormhole[num - 6][1].second;
			else
				wy = wormhole[num - 6][0].first, wx = wormhole[num - 6][0].second;
			process(wy, wx, dir, cnt);
		}
		if (num < 6 && num > 0) {		//블럭 조건 처리
			dir = convDir[num][dir];	//블럭에 따라 방향 변환
			process(ny, nx, dir, cnt + 1);	//점수 + 1
		}
		if (num == 0) {
			process(ny, nx, dir, cnt);
		}
	}
	else {
		if (dir == 0) dir = 2;
		else if (dir == 1) dir = 3;
		else if (dir == 2) dir = 0;
		else if (dir == 3) dir = 1;
		ny = y + dy[dir], nx = x + dx[dir];
		process(ny, nx, dir, cnt + 1);
	}
}
void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sy = i, sx = j;	//시작점 저장
			gameover = false;
			if (!Map[i][j]) {
				process(i, j, 0, 0);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("swea_5650.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N;
		wormhole.assign(5, vector<PII>());	// 최대 5개의 웜홀 초기화
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int a;
				cin >> a;
				Map[i][j] = a;
				if (a >= 6 && a <= 10) {			// 웜홀 위치 저장
					wormhole[a - 6].push_back({ i,j });
				}
			}
		}
		ans = 0;
		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}
