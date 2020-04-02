#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define endl '\n';
#define ll long long
using namespace std;

const int MAX_N = 101;
int n, m, ans;
int num[MAX_N];
bool visit[MAX_N];
void process(int j, int cnt, int sum) {
	if (cnt == 3) {
		if (sum <= m) {
			if (ans < sum)ans = sum;
		}
		return;
	}
	for (int i = j; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			process(i, cnt + 1, sum + num[i]);
			visit[i] = false;
		}
	}
}
void solution_2798() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	process(0, 0, 0);
	printf("%d", ans);
}
int main() {
	solution_2798();
	return 0;
}
