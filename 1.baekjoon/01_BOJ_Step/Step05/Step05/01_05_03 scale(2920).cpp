#include<cstdio>
int Scale[8];
bool isAscending;
int main() {
	freopen("2920.in", "r", stdin);
	for (int idx = 0; idx < 3; idx++) {
		isAscending = false;
		for (int i = 0; i < 8; i++)
			scanf("%d", &Scale[i]);
		if (Scale[0] == 1)isAscending = true;
		for (int i = 1; i < 8; i++) {
			if (isAscending) {
				if (Scale[i - 1] - Scale[i] != -1) {
					printf("mixed\n"); break;
				}
				if (i == 7) printf("ascending\n");
			}
			if (!isAscending) {
				if (Scale[i - 1] - Scale[i] != 1) {
					printf("mixed\n"); break;
				}
				if (i == 7)printf("descending\n");
			}
		}
	}
	return 0;
}