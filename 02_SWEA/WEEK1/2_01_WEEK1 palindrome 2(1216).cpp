#include<cstdio>
char Map[101][101];
int MaxLen;
void Init() {
	MaxLen = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			Map[i][j] = '\0';
		}
	}
}
void Process() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 99; k >= j; k--) {	//양 끝이 같은 곳을 찾기 위함
				bool chk = false;
				int len = k - j + 1;
				for (int l = 0; l < len / 2; l++) {	//회문인지 확인하기 위함
					if (Map[i][j + l] != Map[i][k - l]) {
						chk = true;
						break;
					}
				}
				if (!chk&&MaxLen < len) {
					MaxLen = len;//!chk가 회문
					break;//회문을 찾았으니 더이상 돌 필요가 없음
				}
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 99; k >= j; k--) {	//양 끝이 같은 곳을 찾기 위함
				bool chk = false;
				int len = k - j + 1;
				for (int l = 0; l < len / 2; l++) {	//회문인지 확인하기 위함
					if (Map[j + l][i] != Map[k - l][i]) {
						chk = true;
						break;
					}
				}
				if (!chk&&MaxLen < len) {
					MaxLen = len;
					break;//회문을 찾았으니 더이상 돌 필요가 없음
				}
			}
		}
	}
}
int main() {
	freopen("WEEK1(1216).in.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		Init();
		scanf("%*d");
		for (int j = 0; j < 100; j++) scanf("%s", &Map[j]);
		Process();
		printf("#%d %d\n", i, MaxLen);
	}
	return 0;
}