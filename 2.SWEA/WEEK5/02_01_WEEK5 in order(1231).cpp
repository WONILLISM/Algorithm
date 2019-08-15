#include<cstdio>
const int MAX = 100;
int N, Len;
char Data[MAX + 2], Ans[MAX + 2];
void Init() {
	int k, c, a, b;
	Len = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %c", &k, &c);
		Data[k] = c;
		//터미널 노드를 제외하고 중간 노드들의 자식노드를 먼저 채움
		if (k * 2 <= N) scanf("%d", &a);
		if (k * 2 + 1 <= N)scanf("%d", &b);
	}
}
void Search(int cur) {
	//왼쪽 노드
	if (cur * 2 <= N)Search(cur * 2);
	Ans[Len++] = Data[cur];
	//오른쪽 노드
	if (cur * 2 + 1 <= N)Search(cur * 2 + 1);
}
int main() {
	freopen("WEEK5(1231).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		Search(1);
		Ans[Len] = '\0';
		printf("#%d %s\n", tc, Ans);
	}
	return 0;
}