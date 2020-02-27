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

const int MAX = 21;
int Map[MAX][MAX];
int N, X, ans;

void process(int i, bool dir) {
	int cnt = 1;	// ���� ��ǥ count
	for (int j = 0; j < N - 1; j++) {
		// ���� ��ǥ ���̿� ���� ��ǥ ������ ����
		int d = dir ? Map[i][j + 1] - Map[i][j] : Map[j + 1][i] - Map[j][i];
		if (d == 0)cnt++;	// ���θ� ���� �� �ִٸ� count ����
		else if (d == 1 && cnt >= X)cnt = 1;	// ���� ���̸� �ʰ��Ͽ� �����ٸ� cnt=1�� �ʱ�ȭ
		else if (d == -1 && cnt >= 0)cnt = -X + 1;		
		// �Ʒ��� �������� ��Ȳ�̸� count�� ������������ 0���� X��ŭ �����ֱ� ���� cnt = -X + 1;
		else return;
	}
	if (cnt >= 0) ans++;
}
void solution() {
	for (int i = 0; i < N; i++) {
		process(i, true);	// ture : ����
		process(i, false);	// false : ����
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("swea_4014.in", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ans = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> Map[i][j];

		solution();
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}