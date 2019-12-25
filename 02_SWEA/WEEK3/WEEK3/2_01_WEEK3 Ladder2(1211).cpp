#include<cstdio>
int ladder[102][102];      // ��ٸ� ����, (1,1)���� ������ ����
//Empty = 0, Ladder =1, Goal =2, Visit = 3
int findMinHops(int y, int x, int hop) {
	int cnt = 0;
	int dir[3][2] = { { 0, -1 }, { 0, 1 }, { 1, 0 } };
	if (y == 100) return hop;                       // ���� �����ϸ� �ǳʶ� Ƚ���� ��ȯ
	ladder[y][x] = 3;                       // �� ������ �湮�� ������ ǥ��
	for (int i = 0; i < 3; i++) {
		if (ladder[y + dir[i][0]][x + dir[i][1]] == 1) {
			cnt = findMinHops(y + dir[i][0], x + dir[i][1], hop + 1);
			if (cnt) break;
		}
	}
	ladder[y][x] = 1;  // ���� �˻��� ���� �湮 ǥ�ø� �� ���·� ��ȯ
	return cnt;
}
int main(void) {
	freopen("WEEK3(1211).in.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) {
		int count = 1 << 30;
		int min_count = 1 << 30;
		int min_idx = -1;
		// ���� ���� �ʱ�ȭ
		int s[102] = { 0, }; 
		int sIdx = 0;
		scanf("%*d");
		// Input
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				scanf("%d", &ladder[j][k]);
				if (j == 1 && ladder[j][k] == 1) {
					s[++sIdx] = k;
				}
			}
		}
		for (int j = 1; j <= sIdx; j++) {
			count = findMinHops(1, s[j], 0);
			if (min_count > count) {
				min_count = count;
				min_idx = s[j];
			}
		}
		printf("#%d %d\n", i, min_idx - 1);
	}
}



