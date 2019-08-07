#include<cstdio>
int N, Answer, strLen;
char S[7];
bool visit[1000000][7];
void Init() {
	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < 7; j++)
			visit[i][j] = false;
	for (int i = 0; i < 7; i++)S[i] = '\0';
	scanf("%s ", &S);
	scanf("%d", &N);
	strLen = 0;
	Answer = 0;
	for (int i = 0; S[i] != '\0'; i++)strLen++;
}
void Swap(char *a, char *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int aToi(char *s) {
	int tmp = 0;
	while (*s) {
		tmp = tmp * 10 + (int)(*s - '0');
		s++;
	}
	return tmp;
}
void Process(int step) {
	if (step == N) {
		int a = aToi(S);
		if (Answer < a) Answer = a;
		return;
	}
	for (int i = 0; i < strLen; i++) {
		for (int j = i; j < strLen; j++) {
			if (i != j) {
				Swap(&S[i], &S[j]);
				if (!visit[aToi(S)][step + 1]) {
					visit[aToi(S)][step + 1] = true;
					Process(step + 1);
				}
				Swap(&S[i], &S[j]);
			}
		}
	}
}
int main() {
	freopen("WEEK2(1244).in.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		Init();
		Process(0);
		printf("#%d %d\n", i,Answer);
	}
	return 0;
}