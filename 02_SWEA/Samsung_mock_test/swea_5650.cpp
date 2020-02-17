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
//int visit[MAX][MAX];
int N, ans;
int sx, sy;//������
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int convDir[6][4] = {	//���� ��翡 ���� ������ȯ
	{0,0,0,0},
	{2,0,3,1},
	{2,3,1,0},
	{1,3,0,2},
	{3,2,0,1},
	{2,3,0,1}
};

vector<vector<PII>> wormhole;//��Ȧ ���� ��ġ(y,x)
struct Pinball {
	int y, x, dir, score;
};
//���� ��\(1), ��/(2), \��(3), /��(4), ��(5)
//��Ȧ 6 ~ 10, ����Ȧ -1
//��Ȧ�� �ݵ�� ������ �̷���������� �ݴ������� ����
//�ɺ��� �����ġ�� ���ƿ��ų� ����Ȧ�� ������ ���� ����
//���ӿ��� ���� �� �ִ� �ִ� ����(������ ���̳� ���Ͽ� �ε��� Ƚ��)

bool isRange(int y, int x) { return x > 0 && x <= N && y > 0 && y <= N; }
void process(int y, int x, int dir, int cnt) {
	int ny = y + dy[dir], nx = x + dx[dir];

	int num = Map[ny][nx]; // ��Ȧ ��ȣ ,���� ��ȣ, �� ����, ����Ȧ

	/*if (!num) {
		visit[y][x] = 1;
	}
	else {
		visit[y][x] = cnt;
	}*/

	if (!isRange(ny, nx)) {		//���� ������ �Դ����� �ٽ� �ǵ��� ���� ������ ���� ����*2 +1
		cnt = cnt * 2 + 1;
		ans = max(cnt, ans);
		return;
	}
	else if (ny == sy && nx == sx) {	// ���������� ���ƿ´ٸ�
		ans = max(cnt, ans);
		return;
	}
	else if (!num) {	// �� ���� �̶��
		process(ny, nx, dir, cnt);
	}
	else if (num > 0 && num < 6) {		//���� ���� ó��
		dir = convDir[num][dir];	//������ ���� ���� ��ȯ
		process(ny, nx, dir, cnt + 1);	//���� + 1
	}
	else if (num >= 6 && num <= 10) {		// ��Ȧ ���� ó��

		int wy, wx; //���� ��Ȧ ��ǥ
		if (ny == wormhole[num - 6][0].first && nx == wormhole[num - 6][0].second)
			wy = wormhole[num - 6][1].first, wx = wormhole[num - 6][1].second;
		else
			wy = wormhole[num - 6][0].first, wx = wormhole[num - 6][0].second;
		process(wy, wx, dir, cnt);
	}
	else if (num == -1) {		//����Ȧ�̶��
		ans = max(cnt, ans);
		return;
	}
}
void solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Map[i][j] == 0) {
				sy = i, sx = j;	//������ ����
				process(i, j, 0, 0);
				process(i, j, 1, 0);
				process(i, j, 2, 0);
				process(i, j, 3, 0);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_5650.in", "r", stdin);
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N;
		wormhole.assign(5, vector<PII>());	// �ִ� 5���� ��Ȧ �ʱ�ȭ
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int a;
				cin >> a;
				Map[i][j] = a;
				if (a >= 6 && a <= 10) {			// ��Ȧ ��ġ ����
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