#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long

using namespace std;
const int MAX = 32001;
int N, M;
vector<int> g[MAX];
int entry[MAX];
void solution() {
	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= N; ++i)
		if (!entry[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int i = 0; i < g[cur].size(); ++i) {
			int next = g[cur][i];
			entry[next]--;
			if (!entry[next]) {
				q.push(next);
			}
		}
	}
	for (auto a : ans)
		cout << a << endl;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		entry[v]++;
	}
	solution();
	return 0;
}