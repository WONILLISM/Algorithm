#include<cstdio>
const int MAX = 6561;//3^8
int n;
char star[MAX][MAX];
void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			star[i][j] = ' ';
}
void stamp(int n,int x,int y) {
	if (n == 1) {
		star[y][x] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				stamp(div, x + div * i, y + div * j);
			}
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	init();
	stamp(n, 0, 0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
	return 0;
}