#include <cstdio>

char arr[50][101];
int code[8];
int N, M;
//code  bin     Hex
//  0 : 0001101 (D)
//  1 : 0011001 (19)
//  2 : 0010011 (13)
//  3 : 0111101 (3D)
//  4 : 0100011 (23)
//  5 : 0110001 (31)
//  6 : 0101111 (2F)
//  7 : 0111011 (3B)
//  8 : 0110111 (37)
//  9 : 0001011 (B)
int changeCode(int s) {
	int a;
	switch (s) {
	case 0x0D: a = 0; break;
	case 0x19: a = 1; break;
	case 0x13: a = 2; break;
	case 0x3D: a = 3; break;
	case 0x23: a = 4; break;
	case 0x31: a = 5; break;
	case 0x2F: a = 6; break;
	case 0x3B: a = 7; break;
	case 0x37: a = 8; break;
	case 0x0B: a = 9; break;
	default: break;
	}
	return a;
}
int Process() {
	int k, l, m, sum, result;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int j = 0; j < N; j++) scanf("%s", arr[j]);
	result = 0;
	for (int j = 0; j < N; j++) {
		for (k = 0; k < M; k++) {
			if (arr[j][M - k - 1] == '1') {
				for (l = 0; l < 8; l++) {
					sum = 0;
					for (m = 0; m < 7; m++) {
						int rear = M - k - 1;//뒤부터 조사
						int part = 7 * l; // 7자리씩 끊기
						//rear - part - m -> 뒷자리부터 7자리씩 끊고 m이 7자리가 될때까지 더 빼줌
						sum += (arr[j][rear - part - m] - '0') * (1 << m);
					}
					code[7 - l] = changeCode(sum);
				}
				break;
			}
		}
	}
	if (((code[0] + code[2] + code[4] + code[6]) * 3 + code[1] + code[3] + code[5] + code[7]) % 10 == 0) {
		result = code[0] + code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7];
	}
	return result;
}
int main(void) {
	freopen("WEEK2(1240).in.txt", "r", stdin);
	int tc;
	int l, m, sum, result;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		int answer = Process();
		printf("#%d %d\n", i, answer);
	}
}