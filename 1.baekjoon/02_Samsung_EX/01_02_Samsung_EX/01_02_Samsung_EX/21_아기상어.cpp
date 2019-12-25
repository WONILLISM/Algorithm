#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 20;
int N, ans;
int Size, cntEat;
int Map[MAX][MAX];
int Visit[MAX][MAX];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
typedef struct Shark{
	int x, y, d;
	//Min heap ������ �Ÿ�(d) > y > x
	bool operator < (const Shark &t)const {
		if (d == t.d) {
			if (y == t.y)return x > t.x;
			else return y > t.y;
		}
		else return d > t.d;
	}
};
priority_queue<Shark> pQ;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				pQ.push({ j,i,0 });
				Map[i][j] = 0;
			}
		}
	}
}
void Init(int &curd) {
	curd = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Visit[i][j] = 0;
		}
	}
	while (!pQ.empty())pQ.pop();
}
void Process() {
	while (!pQ.empty()) {
		int curx = pQ.top().x;
		int cury = pQ.top().y;
		int curd = pQ.top().d;
		pQ.pop();
		// ���� ������� ����� ���� ũ�ٸ� ���Դ´�
		if (Map[cury][curx] > 0 && Map[cury][curx] < Size) {
			// ����� ���� Ƚ�� ���
			Map[cury][curx] = 0;
			cntEat++;
			// ���� Ƚ�� = ���� ��� ������ �̸� ��� ������ ����
			if (cntEat == Size) {
				Size++;
				cntEat = 0;
			}
			ans += curd;

			// �ʱ�ȭ
			Init(curd);
		}
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (ny >= 0 && nx >= 0 && ny < N&&nx < N) {
				//Size���� �۰ų� ���ƾ߸� ���� �̵��� �� �ִ�.
				if (!Visit[ny][nx]&&Map[ny][nx]<=Size) {
					pQ.push({ nx,ny,curd + 1 });
					Visit[ny][nx] = 1;
				}
			}
		}
	}
}
void Solution() {
	Input();
	Size = 2;
	Process();
	cout << ans << "\n";
}
int main() {
	freopen("21.in", "r", stdin);
	Solution();
	return 0;
}