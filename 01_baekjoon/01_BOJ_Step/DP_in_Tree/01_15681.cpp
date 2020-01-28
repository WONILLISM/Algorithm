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
int Size[MAX];
vector<int> g[MAX];

int dfs(int cur, int parrent) {
	Size[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (parrent != next) 
			Size[cur] += dfs(next, cur);
	}
	return Size[cur];
}

void solution() {
	int n, r, q; 
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(r, 0);

	while (q--) {
		int t; cin >> t;
		cout << Size[t] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	solution();
	return 0;
}