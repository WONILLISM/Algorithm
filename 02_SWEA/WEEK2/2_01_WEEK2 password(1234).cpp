#include<cstdio>
char P[101];
char Temp[101];
int FindDupl(int l) {
	for (int i = 1; i < l; i++) {
		if (P[i - 1] == P[i]) {
			for (int j = i + 1; j < l; j++) {
				P[j - 2] = P[j];
			}
			l -= 2;
			i -= 2;
		}
		P[l] = '\0';
	}
	return l;
}
int main() {
	freopen("WEEK2(1234).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		for (int i = 0; i < 101; i++)P[i] = '\0';
		int len;
		scanf("%d", &len);
		scanf("%s", P);
		len = FindDupl(len);
		printf("#%d ", tc);
		for (int i = 0; i < len; i++) {
			if (P[i] != 'a')printf("%c", P[i]);
		}
		printf("\n");
	}
	return 0;
}