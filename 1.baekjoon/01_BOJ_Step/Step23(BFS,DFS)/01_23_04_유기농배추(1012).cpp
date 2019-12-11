#include<cstdio>

using namespace std;
const int MAX = 51;
int ans;
int Map[MAX][MAX];
int visit[MAX][MAX];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
typedef struct Pos { int x, y; };
Pos Q[MAX*MAX];
int f, r;
void push(int x, int y) { Q[r++] = { x,y }; }
Pos pop() { return Q[f++]; }
<<<<<<< HEAD

=======
>>>>>>> c709b4320d5428a0bce84aae4e0c6f9471297e54
void Init() {
	f = r = ans = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visit[i][j] = 0;
			Map[i][j] = 0;
		}
	}
}
<<<<<<< HEAD
=======

>>>>>>> c709b4320d5428a0bce84aae4e0c6f9471297e54
int solution(int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j]&&!visit[i][j]) {
				ans++;
				Pos cur = { j,i };
				visit[cur.y][cur.x] = ans;
				push(cur.x, cur.y);
				while (f != r) {
					cur = pop();

					for (int i = 0; i < 4; i++) {
						int nx = cur.x + dx[i], ny = cur.y + dy[i];
						if (ny >= 0 && ny < n&&nx >= 0 && nx < m) {
							if (!visit[ny][nx] && Map[ny][nx]) {
								visit[ny][nx] = ans;
								push(nx, ny);
							}
						}
					}
				}
			}
		}
	}
	return ans;
}
int main() {
	int t, n, m, k;
	freopen("04.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &m, &n, &k);
		Init();
		for (int i = 0; i < k; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			Map[v][u] = 1;
		}
		printf("%d\n", solution(n, m));
	}
	return 0;
}