#include<cstdio>
int score[101];
int Max_Score;
int Max;
void Init() {
	Max = 0, Max_Score = 0;
	for (int i = 0; i < 101; i++)score[i] = 0;
}
void Process() {
	int a;
	for (int i = 0; i < 1000; i++) {
		scanf("%d", &a);
		score[a]++;
	}
	for (int i = 0; i < 101; i++) {
		if (Max < score[i]) {
			Max = score[i];
			Max_Score = i;
		}
		else if (Max == score[i] && Max_Score < i) {
			Max_Score = i;
		}
	}
}
int main() {
	freopen("D2(1204).in.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		Init();
		int a;
		scanf("%d", &a);
		Process();
		printf("#%d %d\n", i, Max_Score);
	}
	return 0;
}