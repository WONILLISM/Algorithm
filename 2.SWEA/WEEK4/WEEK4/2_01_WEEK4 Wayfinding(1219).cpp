#include<cstdio>
int Way, N;
int Arr[100][2];
int Visit[100];
void Init() {
	Way = 0;
	N = 0;
	scanf("%*d%d", &N);
	for (int i = 0; i < 100; i++) {
		Arr[i][0] = Arr[i][1] = -1;
		Visit[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (Arr[a][0] == -1)Arr[a][0] = b;
		else Arr[a][1] = b;
	}
}
void Dfs(int v) {
	if (v == 99) {
		Way = 1;
		return;
	}
	if (Visit[v])return;
	Visit[v] = 1;
	if (Arr[v][0] != -1)Dfs(Arr[v][0]);
	if (Arr[v][1] != -1)Dfs(Arr[v][1]);
	return;
}
int main() {
	freopen("WEEK4(1219).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		Dfs(0);
		printf("#%d %d\n", tc, Way);
	}
	return 0;
}