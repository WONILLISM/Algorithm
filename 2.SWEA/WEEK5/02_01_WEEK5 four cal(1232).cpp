#include<cstdio>
const int MAX = 1000;
int N, childNum[MAX + 2][2];
char Data[MAX + 2][20];

void Init() {
	int k, j;
	char s[20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &k, &s);
		for (j = 0; s[j]; ++j) Data[k][j] = s[j];
		Data[k][j] = '\0';
		if (s[0] < '0')scanf("%d %d", &childNum[k][0], &childNum[k][1]);
	}
}
int ctoi(char *s) {
	int a = s[0] - '0';
	for (int i = 1; s[i]; ++i)a = a * 10 + (s[i] - '0');
	return a;
}
int Search(int cur) {
	if (Data[cur][0] >= '0')return ctoi(Data[cur]);
	int a = Data[cur][0], b = childNum[cur][0], c = childNum[cur][1];
	if (a == '+')return Search(b) + Search(c);
	if (a == '-')return Search(b) - Search(c);
	if (a == '*')return Search(b) * Search(c);
	if (a == '/')return Search(b) / Search(c);
}
int main() {
	freopen("WEEK5(1232).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		Init();
		printf("#%d %d\n", tc, Search(1));
	}
	return 0;
}