#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
#define PII pair<int,int>
#define ABS(x) ( x > 0 ? x : - (x) )
#define INF 10000

using namespace std;

int S[17][17] = { 0, };
int visit[17] = { 0, };
int N, res;
vector<int> A, B;

int calc_taste(vector<int> &v) {
	int x = 0;
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (N / 2); j++) {
			if (i != j) {
				x += S[v[i]][v[j]];
			}
		}
	}
	return x;
}
int process() {
	vector<int> a;
	vector<int> b;

	for (int i = 1; i <= N; i++) {
		if (visit[i]) a.push_back(i);
		else b.push_back(i);
	}
	return ABS(calc_taste(a) - calc_taste(b));
}
void solution(int k, int cnt) {
	visit[k] = true;
	if (cnt == N / 2) {
		res = min(res, process());
	}
	else {
		for (int i = k + 1; i <= N; i++) {
			solution(i, cnt + 1);
		}
	}
	visit[k] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		res = INF;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> S[i][j];
		solution(1, 1);
		cout << "#" << tc << ' ' << res << '\n';
	}
	return 0;
}