#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
using namespace std;

const int MAX = 101;
int ans, N, M, K;
struct Micro {
	int y, x, n, dir;	// ��ġ, ��, ����;
};
int Map[MAX][MAX][2];	// �̻��� ���� �ε��� ������ ��ǥ�� �̻����� ��

int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int convDir[] = { 0,2,1,4,3 };// ��>��, ��>��, ��>��, ��>��
vector<Micro> v;

bool isEdge(int y, int x) { return x == 0 || x == N - 1 || y == 0 || y == N - 1; }
void solution() {
	while (M--) {
		fill(&Map[0][0][0], &Map[N - 1][N - 1][0], 0);
		fill(&Map[0][0][1], &Map[N - 1][N - 1][1], 0);
		for (int i = 1; i <= K; i++) {
			Micro &mic = v[i];

			//�̻��� ���� 0�� �ƴϸ� ����ִ� ����
			if (mic.n) {
				int ny = mic.y + dy[mic.dir], nx = mic.x + dx[mic.dir];
				mic.y = ny;
				mic.x = nx;
				//��迡 ����� �� ó�� 
				if (isEdge(ny, nx)) {
					mic.dir = convDir[mic.dir];
					mic.n /= 2;
				}
				// ���� ��ǥ�� �̻����� ������
				if (!Map[ny][nx][0]) {
					Map[ny][nx][0] = i;
					Map[ny][nx][1] = mic.n;
				}
				// ���� ��ǥ�� �̻����� ������
				else {
					int idx = Map[ny][nx][0];
					v[idx].n += mic.n;

					// �ش� ��ǥ�� �������� �� ������ �ڽ��� �������� �ٲٰ� �̻��� ���� �ٲ۴�.
					if (Map[ny][nx][1] < mic.n) {
						Map[ny][nx][1] = mic.n;
						v[idx].dir = mic.dir;
					}
					//ó���� �Ϸ�Ǹ� �̻����� ���������.
					mic.n = 0;
				}
			}
		}
	}
	
	for (int i = 1; i <= K; i++) ans += v[i].n;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_2382.in", "r", stdin);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> M >> K;
		/*--- Init ---*/
		ans = 0;
		v.clear();

		/*--- Input ---*/
		v.push_back({ 0,0,0,0 });
		for (int i = 0; i < K; i++) {
			int y, x, n, dir;
			cin >> y >> x >> n >> dir;
			v.push_back({ y,x,n,dir});
		}
		solution();
		cout << "#" << tc << " " << ans << endl;
	}

	return 0;
}