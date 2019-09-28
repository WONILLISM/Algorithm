#include<cstdio>
char P[80];
int main() {
	int t;
	scanf("%d ", &t);
	while (t--) {
		int Score = 0, Answer = 0;
		scanf("%s ", P);
		int i = 0;
		while (P[i]) {
			if (P[i] == 'O') {
				Score++;
				Answer += Score;
			}
			if (P[i] == 'X') Score = 0;
			i++;
		}
		printf("%d\n", Answer);
	}
	return 0;
}