#include<cstdio>
int SecretCode[8];
void Process() {
	for (int i = 1;;i++) {
		int tmp = 0;
		tmp = SecretCode[0];
		for (int j = 1; j < 8; j++) {
			SecretCode[j - 1] = SecretCode[j];
		}
		SecretCode[7] = tmp - i;
		if (i == 5)i = 0;
		if (SecretCode[7] <= 0) {
			SecretCode[7] = 0;
			return;
		}
	}
}
int main() {
	freopen("WEEK2(1225).in.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%*d");
		for (int i = 0; i < 8; i++) scanf("%d", &SecretCode[i]);
		printf("#%d", tc);
		Process();
		for (int i = 0; i < 8; i++) printf(" %d", SecretCode[i]);
		printf("\n");
	}
	return 0;
}
//9550 9556 9550 9553 9558 9551 9551 9551 