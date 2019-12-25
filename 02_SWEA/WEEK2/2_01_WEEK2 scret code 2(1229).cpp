#include<cstdio>
int Code[1000];
int Tmp[1000];
int N, M;
void ComdInput() {
	int x, y;
	scanf("%d%d", &x, &y);
	for (int j = x; j < N; j++) {
		Tmp[j] = Code[j];
		Code[j] = 0;
	}
	for (int j = x; j < N; j++) Code[j + y] = Tmp[j];
	for (int i = 0; i < y; i++) scanf("%d", &Code[x + i]);
	N += y;
}
void ComdDelete() {
	int x, y;
	scanf("%d%d", &x, &y);
	for (int i = x; i < N; i++) {
		Code[i] = Code[i + y];
	}
	N -= y;
}
void Process() {
	for (int i = 0; i < 1000; i++)Code[i] = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Code[i]);
	}
	scanf("%d\n", &M);
	for (int i = 0; i < M; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'I')ComdInput();
		else if (c == 'D') ComdDelete();
	}
}
int main() {
	freopen("WEEK2(1229).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Process();
		printf("#%d", tc);
		for (int i = 0; i < 10; i++)printf(" %d", Code[i]);
		printf("\n");
	}
	return 0;
}