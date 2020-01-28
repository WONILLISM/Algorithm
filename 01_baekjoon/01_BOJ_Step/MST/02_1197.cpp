#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int ans;
vector<int> p;
struct graph { int v1, v2, cost; };
bool comp(graph a, graph b) { return a.cost < b.cost; }
int _find(int x) {
	if (p[x] == x)return x;
	else return p[x] = _find(p[x]);
}
void _union(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x != y)p[x] = y;
}
bool isSameParent(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x == y) return true;
	else return false;
}
void solution() {
	vector<graph> g;
	int n, m;//정점, 간선
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)p.push_back(i);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g.push_back({ a - 1,b - 1,c});
	}
	sort(g.begin(), g.end(), comp);
	for (int i = 0; i < m; i++) {
		int v1 = g[i].v1, v2 = g[i].v2, cost = g[i].cost;
		if (!isSameParent(v1, v2)) {
			_union(v1, v2);
			ans += cost;
		}
	}
	cout << ans << endl;
}
int main() {
	solution();
	return 0;
}