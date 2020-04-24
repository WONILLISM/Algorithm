#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define PII pair<int,int>

using namespace std;

const int MAX = 20;

int A[MAX][MAX];
int visit[MAX][MAX];
int visit2[MAX][MAX];
int N, ans = 1<<30, total;	// 행, 열값 / 정답 / 전체 인구
vector<PII> boundary;	// 경계 꼭지점 좌표 저장
int dist[4];		// 경계 변의 길이
int bx[] = { 1,-1,-1,1 };
int by[] = { 1,1,-1,-1 };

struct cntArea { int y, x; };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int Area[5];
PII limit[4] = { {3,0},{1,0},{1,2},{3,2} };

bool isRanged(int ny, int nx, int num) {
	if (num == 0)
		return ny >= 1 && ny < boundary[limit[num].first].second&&nx >= 1 && nx <= boundary[limit[num].second].first;
	else if (num == 1)
		return ny >= 1 && ny <= boundary[limit[num].first].second&&nx > boundary[limit[num].second].first && nx <= N;
	else if (num == 2)
		return ny > boundary[limit[num].first].second&& ny<=N && nx >= boundary[limit[num].second].first && nx <= N;
	else if (num == 3)
		return ny >= boundary[limit[num].first].second&& ny<=N&&nx>=1&& nx < boundary[limit[num].second].first;
}

//bfs
void countArea(int num) {
	Area[num] = 0;
	queue<cntArea> q;
	//기준점
	int y = boundary[num].first;
	int x = boundary[num].second;
	//시작점
	int sy, sx;
	if (num == 0)sy = 1, sx = 1;
	else if (num == 1)sy = 1, sx = N;
	else if (num == 2)sy = N, sx = N;
	else if (num == 3)sy = N, sx = 1;
	q.push({ sy,sx });
	visit2[sy][sx] = num + 1;
	Area[num] += A[sy][sx];
	while (!q.empty()) {
		int cy = q.front().y, cx = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isRanged(ny, nx,num)) {
				if (visit[ny][nx]!=5 &&visit2[ny][nx]!=num+1) {
					visit2[ny][nx] = num + 1;
					q.push({ ny,nx});
					Area[num] += A[ny][nx];
				}
			}
		}
	}
}
// dfs
void area(int y, int x, int dir, int step) {
	if (dir == 3) {
		if (y == boundary[0].first + 1 && x == boundary[0].second - 1) {
			for (int i = 0; i < 4; i++) {
				countArea(i);
			}
			
			
			for (auto res : boundary)
				cout << res.first << " " << res.second << "  ";
			cout << endl;
			cout << endl;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					cout << visit[i][j]<<" ";
					visit2[i][j] = 0;
				}
				cout << endl;
			}
			int M = 0, m = 1 << 30;
			int sum = 0;
			for (int i = 0; i < 4; i++) {
				sum += Area[i];
			}


			Area[4] = total - sum;
			//for (int i = 0; i < 5; i++)
			//	cout << Area[i] << " ";
			//cout << endl;
			sort(Area, Area + 5);
			ans = min(ans, Area[4] - Area[0]);
			return;
		}
	}

	int ny = y + by[dir], nx = x + bx[dir];
	if (ny >= 1 && ny <= N&&nx >= 1 && nx <= N && visit[ny][nx] != 5) {
		visit[ny][nx] = 5;
		//visit[ny][nx] = -1;
		area(ny, nx, dir, step + 1);	// 회전안함		

		dist[dir] = step;
		step = 0;
		boundary.push_back({ ny,nx });
		area(ny, nx, dir + 1, step + 1); // 회전
		boundary.pop_back();
		visit[ny][nx] = 0;
	}
}

int solution() {

	// 구역 나누기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			boundary.push_back({ i,j });
			visit[i][j] = 5;
			//visit[i][j] = -1;
			area(i, j, 0, 1);
			visit[i][j] = 0;
			boundary.pop_back();
		}
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			total += A[i][j];
		}
	}
	cout << solution() << endl;
}