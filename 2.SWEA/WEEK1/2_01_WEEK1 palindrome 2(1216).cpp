#include<cstdio>
char Map[101][101];
int MaxLen;
void Init() {
	MaxLen = 0;
	for(int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			Map[i][j] = 0;
		}
	}
}
void Process() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			bool chk = false;
			for (int k = j; k < 100; k++) {
				if (Map[i][j] == Map[i][99 - k]) {
					int len = 99 - k - j + 1;
					for (int l = 0; l < len / 2; l++) {
						if (Map[i][j + l] != Map[i][99 - l]) {
							chk = true;
							break;
						}
					}
					if (!chk&&MaxLen < len)MaxLen = len;
				}
				if (!chk) break;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			bool chk = false;
			for (int k = j; k < 100; k++) {
				if (Map[j][i] == Map[99 - k][i]) {
					int len = 99 - k - j + 1;
					for (int l = 0; l < len / 2; l++) {
						if (Map[j + l][i] != Map[99 - l][i]) {
							chk = true;
							break;
						}
					}
					if (!chk&&MaxLen < len)MaxLen = len;
				}
				if (!chk) break;
			}
		}
	}
}
int main() {
	freopen("D2(1216).in.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		Init();
		scanf("%*d");
		for (int j = 0; j < 100; j++) scanf("%s", &Map[j]);
		Process();
		printf("#%d %d\n", i, MaxLen);
	}
	return 0;
}