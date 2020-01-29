#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX = 1e5 + 1;

vector<int> g[MAX]; //���� ����Ʈ
vector<int> tree[MAX]; //dfs Ʈ��
int w[MAX]; //����ġ
int dp[MAX][2]; //1�� ��Ʈ�� ���°�, �Ⱦ��°� dp

void dfs(int cur, int prv) {
	for (auto next : g[cur]) {
		if (next != prv) {
			tree[cur].push_back(next);
			dfs(next, cur);
		}
	}
}
void solution() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		dp[i][0] = dp[i][1] = -1;
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solution();
	return 0;
}