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

vector<int> g[MAX]; //인접 리스트
int w[MAX]; //가중치

void solution() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solution();
	return 0;
}