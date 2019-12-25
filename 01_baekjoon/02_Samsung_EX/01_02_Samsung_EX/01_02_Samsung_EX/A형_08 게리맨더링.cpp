#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define endl "\n"
const int MAX = 11;
int N, Ans = 1 << 30;
int People[MAX][2];
int visit[MAX];
int Map[MAX][MAX];

bool bfs(vector<int> v, int select) {
	int cnt = 1;
	queue<int> q;
	q.push(v[0]);
	visit[v[0]] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (Map[cur][i] && People[i][1] == select && !visit[i]) {
				visit[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
	if (v.size() == cnt)return true;
	return false;
}
bool chk() {
	vector<int> a, b;
	for (int i = 1; i <= N; i++) {
		if (People[i][1])a.push_back(i);
		else b.push_back(i);
	}
	if (a.size() == 0 || b.size() == 0)return false;
	if (!bfs(a, 1))return false;
	if (!bfs(b, 0))return false;
	return true;
}
void process(int v, int cnt) {
	if (cnt >=1) {
		for (int i = 1; i <= N; i++)visit[i] = 0;
		if (chk()) {
			int Num[2] = { 0, };
			for (int i = 1; i <= N; i++) {
				if (People[i][1] == 1)Num[1] += People[i][0];
				else Num[0] += People[i][0];
			}
			int tmp = Num[0] - Num[1] > 0 ? Num[0] - Num[1] : Num[1] - Num[0];
			if (Ans > tmp)Ans = tmp;
		}
	}
	for (int i = v; i <= N; i++) {
		if (!People[i][1]) {
			People[i][1] = 1;
			process(i, cnt + 1);
			People[i][1] = 0;
		}
	}
}
void solution() {
	process(1, 0);
	if (Ans == 1 << 30)cout << "-1" << endl;
	else cout << Ans << endl;
}
int main() {
	freopen("a_08.in", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> People[i][0];
	for (int i = 1; i <= N; i++) {
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			Map[i][a] = Map[a][i] = 1;
		}
	}
	solution();
	return 0;
}