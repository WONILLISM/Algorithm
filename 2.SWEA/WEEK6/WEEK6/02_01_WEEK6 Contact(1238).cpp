#include<cstdio>
const int MAX = 100;
int N, Start, Ans, Max_Step;
int Data[MAX + 1][MAX + 1];
int Visit[MAX + 1];
int Q[MAX], f, r;
void Init() {
	f = 0; r = 0;
	Max_Step = 0;
	for (int i = 0; i < MAX + 1; i++)Visit[i] = 0;
	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= MAX; j++)
			Data[i][j] = 0;
	scanf("%d %d", &N, &Start);
	for (int i = 0; i < N; i+=2) {
		int a, b;
		scanf("%d %d", &a, &b);
		Data[a][b] = 1;
	}
}
void BFS(int v) {
	int cur = v;
	Visit[cur] += 1;
	Q[r++] = cur;
	while (f != r) {
		cur = Q[f++];
		for (int i = 1; i <= MAX; i++) {
			if (!Visit[i] && Data[cur][i]) {
				Q[r++] = i;
				Visit[i] = Visit[cur] + 1;
				if (Max_Step < Visit[i])Max_Step = Visit[i];
			}
		}
	}
}
int main() {
	freopen("WEEK6(1238).in.txt", "r", stdin);
	//freopen("Test.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		BFS(Start);
		for (int i = 1; i <= MAX; i++)
			if (Visit[i] == Max_Step)Ans = i;
		printf("#%d %d\n", tc, Ans);
	}
	return 0;
}

/*
24 2
1 17 3 22 1 8 1 7 7 1 2 7 2 15 15 4 6 2 11 6 4 10 4 2
*/