#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

vector<int> v;

int find(int x) {
	if (x == v[x])return x;
	else return v[x] = find(v[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)
		v[y] = x;
}
void solution_1717() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)v.push_back(i);

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (!a) {
			Union(b, c);
		}
		else {
			if (find(b) == find(c))printf("YES\n");
			else printf("NO\n");
		}
	}
}
int main() {
	solution_1717();
	return 0;
}
