#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

int N;
double ans;
vector<int> p;
struct graph { double cost; int v1, v2; };
bool comp(graph a, graph b) { return a.cost < b.cost; }
struct Pos { double x, y; };
vector<graph> g;
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
	if (x != y)return false;
	else return true;
}
void solution() {
	vector<Pos> pos;
	for (int i = 0; i < N; i++) {
		double a, b;
		scanf("%lf%lf", &a, &b);
		pos.push_back({ a,b });
		p.push_back(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			double c = sqrt((pos[i].x - pos[j].x)*(pos[i].x - pos[j].x) + (pos[i].y - pos[j].y)*(pos[i].y - pos[j].y));
			g.push_back({ c,i,j });
		}
	}
	sort(g.begin(), g.end(), comp);
	for (int i = 0; i < g.size(); i++) {
		int v1 = g[i].v1, v2 = g[i].v2;
		double cost = g[i].cost;
		if (!isSameParent(v1, v2)) {
			_union(v1, v2);
			ans += cost;
		}
	}
	printf("%0.2f", ans);
}
int main() {
	scanf("%d", &N);
	solution();
	return 0;
}