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

const int MAX = 11;
int N, M, C, ans;
int Map[MAX][MAX];
int visit[MAX][MAX];

vector<int> v;
int Sum[6];

// ��ġ, ���� �� ī��Ʈ, ä�뷮 ����, ���� ����
void process(int y, int x, int cnt, int sum, int total) {	
	if (sum > C)return;
	ans = max(ans, total);
	if (cnt == M)return;

	process(y, x + 1, cnt + 1, sum + Map[y][x], total + pow(Map[y][x], 2));
	process(y, x + 1, cnt + 1, sum, total);
}
int solution(int y, int x) {
	ans = 0;
	int A = 0, B = 0; // A�� B�� ä�� ��
	
	process(y, x, 0, 0, 0);	// A���� ä��
	for (int i = 0; i < M; i++)	// A�� ä���� ���� B�� ä���� �� �����Ƿ� �湮üũ �ص�
		visit[y][x + i] = 1;
	A = ans;

	// ���� ä���� A�� ���Ͽ� ��� B�� ����� ���� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - M + 1; j++) {
			if (!visit[i][j]) {
				ans = 0;
				process(i, j, 0, 0, 0);
				B = max(B, ans);
			}
		}
	}
	
	return A + B;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("swea_2115.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> N >> M >> C;
		fill(&visit[0][0], &visit[MAX][MAX], 0);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> Map[i][j];
			}
		}
		int ans = 0;
		//��� A�� ����� �� 
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N - M + 1; j++) {
				int res = solution(i, j);
				ans = max(ans, res);
			}
		}
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}