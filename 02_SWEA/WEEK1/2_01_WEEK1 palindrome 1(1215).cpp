#include<cstdio>
int Len, cnt;
char Map[8][9];
void Init() {
	cnt = 0;
	Len = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			Map[i][j] = 0;
}
void Process() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8 - Len+1; j++) {
			bool chk = false;
			for (int k = 0; k < Len / 2; k++)
				if (Map[i][j + k] != Map[i][j + Len - k - 1])chk = true;
			if (!chk)cnt++;
		}
	}
	for (int i = 0; i < 8 - Len+1; i++) {
		for (int j = 0; j < 8; j++) {
			bool chk = 0;
			for (int k = 0; k < Len / 2; k++)
				if (Map[i + k][j] != Map[i + Len - k - 1][j])chk = true;
			if (!chk)cnt++;
		}
	}
}
int main() {
	freopen("D2(1215).in.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		Init();
		scanf("%d", &Len);
		for (int j = 0; j < 8; j++)
			scanf("%s", Map[j]);
		Process();
		printf("#%d %d\n", i, cnt);
	}
	return 0;
}